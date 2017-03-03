#ifndef __TS_DB_H__
#define __TS_DB_H__

#include "ts_session.h"

#include <json/json.h>
//#include <sqlite3.h>
#include <ex.h>

// #include <map>
// typedef std::map<long, sqlite3*> sqlite3Map;
// 
// typedef struct TS_DB_AUTH_INFO
// {
// 	ex_astr host_ip;
// 	int host_port;
// 	int host_lock;
// 	int sys_type;
// 	int protocol;
// 	int is_encrypt;
// 	int auth_mode;
// 	int account_lock;
// 	ex_astr user_name;
// 	ex_astr user_auth;
// 	ex_astr user_param;
// 	ex_astr account_name;
// }TS_DB_AUTH_INFO;
// 
// typedef struct TS_DB_AUTH_INFO_2
// {
// 	int auth_id;
// 	int host_id;
// 	ex_astr host_ip;
// 	int pro_type;
// 	int auth_mode;
// 	int host_lock;
// }TS_DB_AUTH_INFO_2;

// typedef struct TS_DB_AUTH_INFO_3
// {
// 	int host_id;
// 	ex_astr host_ip;
// 	ex_astr host_user_name;
// 	ex_astr host_user_pwd;
// 	int auth_mode;
// 	int cert_id;
// 	ex_astr cert_name;
// 	ex_astr cert_pri;
// 	ex_astr cert_pub;
// 	
// }TS_DB_AUTH_INFO_3;

// typedef struct TS_DB_SERVER_CONFIG
// {
// 	ex_astr ts_server_rpc_ip;
// 	int ts_server_rpc_port;
// 	int ts_server_rdp_port;
// 	int ts_server_ssh_port;
// 	int ts_server_telnet_port;
// }TS_DB_SERVER_CONFIG;

// typedef std::vector<TS_DB_AUTH_INFO_2> AuthInfo2Vec;
// typedef std::vector<TS_DB_AUTH_INFO_3> AuthInfo3Vec;
class TsDB
{
public:
	TsDB();
	~TsDB();

	// 根据认证ID获取认证信息（包括服务器IP、端口，用户名、密码或私钥、协议如RDP或SSH等等）
	bool get_auth_info(int auth_id, Json::Value& jret);

	// 重置log日志状态
	bool update_reset_log();
	// 记录会话的开始
	bool session_begin(TS_SESSION_INFO& info, int& record_id);
	//session 结束
	bool session_end(int id,int ret_code);

// protected:
// 	sqlite3* get_db();
// private:
// 	ExThreadLock m_lock;
// 	sqlite3Map	m_sqlite3Map;
};

extern TsDB g_db;

#endif // __TS_DB_H__
