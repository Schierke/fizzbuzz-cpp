
#ifndef EXAMPLE_POSTGRESQL_USERDB_HPP
#define EXAMPLE_POSTGRESQL_USERDB_HPP

#include "dto/FizzBuzzDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * UserDb client definitions.
 */
class FizzBuzzDb : public oatpp::orm::DbClient {
public:

  FizzBuzzDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/init_001.sql");
    // TODO - Add more migrations here.
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("FizzBuzzDb", "Migration - OK. Version=%d.", version);

  }

  QUERY(insertFizzBuzz,
        "INSERT INTO FizzBuzz"
        "(id, int1, int2, str1, str2, max_limit, time_stamp) VALUES "
        "(uuid_generate_v4(), :fb.int1, :fb.int2, :fb.str1, :fb.str2, :fb.max_limit, now());",
        PREPARE(true), // user prepared statement!
        PARAM(oatpp::Object<FizzBuzzDto>, fb))

  QUERY(getStats,
        "SELECT COUNT(*) as hits, int1, int2, str1, str2, max_limit FROM FizzBuzz "
        "GROUP BY int1, int2, str1, str2, max_limit "
        "ORDER BY hits DESC "
        "LIMIT 1;",
        PREPARE(true)) //<-- user prepared statement!

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //EXAMPLE_POSTGRESQL_USERDB_HPP
