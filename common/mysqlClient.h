#ifndef CPP_UTIL_COMMON_MYSQLCLIENT_H
#define CPP_UTIL_COMMON_MYSQLCLIENT_H

#include <mysql.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace Util {
    
class MysqlClient {
public:
    MysqlClient(const string& host, size_t port, const string& user, const string& passwd, 
            const string& db, const string charset = "utf8");
    virtual ~MysqlClient();

private:
    bool Init();

private:
    typedef vector< vector<string> > RowsType;

public:
    /*
     * 1. execute sql, return true/false
     * */
    bool ExecuteSql(const string& sql);

    /*
     * 1. select data from table, return true/false
     * */
    bool Select(const string& sql, RowsType& rows);

    /*
     * 1. insert value to table, return true/false 
     * 2. keyTypeVec is all keys type
     *    s-> string type, contain char, varchar, Text...
     *    num-> numbers, int, double ...
     * */
    bool Insert(const string& tableName, const vector<string>& keyVec, const vector<string>& valVec, 
            const vector<string>& keyTypeVec);

    /*
     * 1. update value to table, return true/false
     * 2. keyTypeVec is all keys type
     *    s-> string type, contain char, varchar, Text...
     *    num-> numbers, int, double ...
     * */
    bool Update(const string& tableName, const vector<string>& keyVec, const vector<string>& valVec, 
            const vector<string>& keyTypeVec, const string& condition);

    /*
     * 1. delete table, return true/false
     * */
    bool Delete(const string& tableName, const string& condition);

private:
    const string mHost;
    const size_t mPort;
    const string mUser;
    const string mPasswd;
    const string mDb;
    const string mCharset;
    MYSQL* mMysqlConn;
}; //class MysqlClient 

} //namespace Util
#endif //CPP_UTIL_COMMON_MYSQLCLIENT_H
