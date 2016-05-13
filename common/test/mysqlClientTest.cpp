#include <vector>
#include <gtest/gtest.h>
#include "common/mysqlClient.h"

using namespace std;
using namespace Util;

TEST(TestMysqlClient, Init) {
    #if 0
    string host = "localhost";
    size_t port = 3306;
    string user = "xxx";
    string passwd = "xxx"; //password
    string db = "test";
    MysqlClient mysqlClient(host,port,user,passwd,db);
   
    typedef vector< vector<string> > RowsType;
    RowsType rows;
    string sql = "select * from test_table";
    ASSERT_TRUE(mysqlClient.Select(sql, rows));

    vector<string> keyVec;
    keyVec.push_back("name");
    keyVec.push_back("age");
    keyVec.push_back("address");

    vector<string> valVec;
    valVec.push_back("chenguolin");
    valVec.push_back("18");
    valVec.push_back("zjhz");

    vector<string> keyTypeVec;
    keyTypeVec.push_back("str");
    keyTypeVec.push_back("num");
    keyTypeVec.push_back("str");

    ASSERT_TRUE(mysqlClient.Insert("test_table", keyVec, valVec, keyTypeVec));

    valVec[1] = "19";

    ASSERT_TRUE(mysqlClient.Update("test_table", keyVec, valVec, keyTypeVec, "name = 'chenguolin'"));
    rows.clear();
    ASSERT_TRUE(mysqlClient.Select(sql, rows));
    ASSERT_EQ(rows[0][0], "chenguolin");
    ASSERT_EQ(rows[0][1], "19");
    ASSERT_EQ(rows[0][2], "zjhz");

    ASSERT_TRUE(mysqlClient.Delete("test_table", "name = 'chenguolin'"));
    rows.clear();
    ASSERT_TRUE(mysqlClient.Select(sql, rows));
    ASSERT_EQ((size_t)0, rows.size());
    #endif
}
