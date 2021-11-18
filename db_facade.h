// db_facade.h 18/11/2021
/* ========================================================================== */
#pragma once

/* ========================================================================== */
#include <mysql/mysql.h>
#include <iostream>

/* ========================================================================== */
namespace db_facade {

/* ========================================================================== */
class DbFacade {
 public:
  DbFacade();
  ~DbFacade();

 public:
  bool init(const std::string &host, const std::string &db_name,
            const std::string &user, const std::string &password,
            const int64_t port, unsigned long flags);

 public:
  bool connect();
  bool reconnect();
  bool disconnect();
  bool rollback();
  bool commit();

 private:
  MYSQL mysql_;

 private:
  int64_t port_;
  std::string host_;
  std::string user_;
  std::string db_name_;
  std::string password_;

  unsigned long flags_;
};

/* ========================================================================== */
}  // namespace db_facade
/* ========================================================================== */
