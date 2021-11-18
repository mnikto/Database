// db_facade.cc 18/11/2021
/* ========================================================================== */
#include "db_facade.h"

/* ========================================================================== */
using namespace db_facade;

/* ========================================================================== */
DbFacade::DbFacade() {
  auto err_code = mysql_library_init(0, nullptr, nullptr);
  if (err_code) {
    std::cerr << "mysql_library_init returns code = " << err_code << std::endl;
    std::exit(err_code);
  }
}

/* ========================================================================== */
DbFacade::~DbFacade() {
  disconnect();
  ::mysql_library_end();
}

/* ========================================================================== */
bool DbFacade::init(const std::string &host, const std::string &db_name,
                    const std::string &user, const std::string &password,
                    const int64_t port, unsigned long flags) {
  port_ = port;
  host_ = host;
  user_ = user;
  flags_ = flags;
  db_name_ = db_name;
  password_ = password;

  return true;
}

/* ========================================================================== */
bool DbFacade::connect() {
  if (not mysql_init(&mysql_)) {
    std::cerr << "Mysql init failed!" << std::endl;
    return false;
  }

  /* TODO: Добавить mysql options */

  if (not mysql_real_connect(&mysql_, host_.c_str(), user_.c_str(),
                             password_.c_str(), db_name_.c_str(), port_,
                             nullptr, flags_)) {
    std::cerr << "Mysql real connect failed!" << std::endl;
    return false;
  }

  return true;
}

/* ========================================================================== */
bool DbFacade::reconnect() { return true; }

/* ========================================================================== */
bool DbFacade::disconnect() {
  mysql_close(&mysql_);
  return true;
}

/* ========================================================================== */
bool DbFacade::rollback() { return mysql_rollback(&mysql_); }

/* ========================================================================== */
bool DbFacade::commit() { return mysql_commit(&mysql_); }

/* ========================================================================== */
