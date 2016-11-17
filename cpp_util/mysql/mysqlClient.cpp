#include "logger.h"
#include "mysqlClient.h"
#include "stringUtil.h"

using namespace std;
namespace Util {

MysqlClient::MysqlClient(const string& host, size_t port, const string& user, const string& passwd, 
        const string& db, const string charset)
    :mHost(host), mPort(port), mUser(user), mPasswd(passwd), 
    mDb(db), mCharset(charset), mMysqlConn(NULL) {
        assert(Init());
}

MysqlClient::~MysqlClient() {
    if(mMysqlConn != NULL) {
        mysql_close(mMysqlConn);
    }
}

bool MysqlClient::Init() {
    mMysqlConn = mysql_init(NULL);
    if(NULL == mMysqlConn) {
        LogError("MysqlClient mysql_init faield. %s", mysql_error(mMysqlConn));
        return false;
    }
    //set reconenct
    bool reConn = true;
    mysql_options(mMysqlConn, MYSQL_OPT_RECONNECT, &reConn);
    if (NULL == mysql_real_connect(mMysqlConn, mHost.c_str(), mUser.c_str(), 
                mPasswd.c_str(), mDb.c_str(), mPort, NULL, 0)) {
        LogError("MysqlClient mysql_real_connect failed. %s", mysql_error(mMysqlConn));
        mysql_close(mMysqlConn);
        mMysqlConn = NULL;
        return false;
    }  
    // 1. 0 -> success
    // 2. non 0 -> fail
    if(mysql_set_character_set(mMysqlConn, mCharset.c_str())) {
        LogError("MysqlClient mysql_set_character_set [%s] failed.", mCharset.c_str());
        return false;
    }
    return true;
}

bool MysqlClient::ExecuteSql(const string& sql) {
    assert(mMysqlConn != NULL);
    if(mysql_query(mMysqlConn, sql.c_str())) {
        LogError("mysql_query [%s] failed, [%s]", sql.c_str(), mysql_error(mMysqlConn));
        return false;
    }
    return true;
}

bool MysqlClient::Select(const string& sql, RowsType& rows) {
    if(!ExecuteSql(sql)) {
        LogError("Select executeSql failed. [%s]", sql.c_str());
        return false;
    }
    MYSQL_RES* result = mysql_store_result(mMysqlConn);
    if(NULL == result) {
        LogError("mysql_store_result failed.[%d]", mysql_error(mMysqlConn));
        return false;
    }
    size_t fieldsNum = mysql_num_fields(result);
    MYSQL_ROW row;
    // fetch row do process
    while((row = mysql_fetch_row(result))) {
        vector<string> vec;
        for(size_t i = 0; i < fieldsNum; i++) {
            if (row[i] != "") {
                vec.push_back(row[i]);
            }
            else {
                vec.push_back("NULL");
            }
        }
        rows.push_back(vec);
    }
    mysql_free_result(result);
    return true;
}

bool MysqlClient::Insert(const string& tableName, const vector<string>& keyVec, const vector<string>& valVec,
        const vector<string>& keyTypeVec) {
    assert(keyVec.size() == valVec.size());
    size_t size = keyVec.size();
    string keys = "";
    string values = "";
    for (size_t i = 0; i < size; i++) {
        keys = keys + keyVec[i];
        if (keyTypeVec[i] == "str") {
            values = values + "'" + valVec[i] + "'";
        }
        else {
            values = values + valVec[i]; 
        }
        if (i != (size-1)) {
            keys += ",";
            values += ",";
        }
    }
    string sql = "";
    StringUtil::StringFormat(sql, "insert into %s (%s) values (%s)", tableName.c_str(), keys.c_str(), values.c_str());
    return ExecuteSql(sql);
}

bool MysqlClient::Update(const string& tableName, const vector<string>& keyVec, const vector<string>& valVec, 
        const vector<string>& keyTypeVec, const string& condition) {
    assert(keyVec.size() == valVec.size());
    size_t size = keyVec.size();
    string setVals = "";
    for (size_t i = 0; i < size; i++) {
        if (keyTypeVec[i] == "str") {
            setVals = setVals + keyVec[i] + "=" + "'" + valVec[i] + "'";
        }
        else {
            setVals = setVals + keyVec[i] + "=" + valVec[i];
        }
        if (i != (size-1)) {
            setVals += ",";
        }
    }
    string sql = "";
    StringUtil::StringFormat(sql, "update %s set %s where %s", tableName.c_str(), setVals.c_str(), condition.c_str());
    return ExecuteSql(sql);
}

bool MysqlClient::Delete(const string& tableName, const string& condition) {
    string sql = "";
    StringUtil::StringFormat(sql, "delete from %s where %s", tableName.c_str(), condition.c_str());
    if(!ExecuteSql(sql)) {
        LogError("Delete executeSql failed. [%s]", sql.c_str());
        return false;
    }
    return true;
}

} //namespace Util
