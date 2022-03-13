CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

DROP TABLE IF EXISTS FizzBuzz;


CREATE TABLE IF NOT EXISTS FizzBuzz (
    id          varchar (256) PRIMARY KEY,
    int1        int NOT NULL,
    int2        int NOT NULL,
    str1        varchar (256) NOT NULL,
    str2        varchar (256) NOT NULL,
    max_limit   int NOT NULL,

    time_stamp  timestamp without time zone NOT NULL
);
