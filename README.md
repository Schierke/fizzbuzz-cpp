# FizzBuzz REST Server

A simple REST server to solve simple Fizz-Buzz problem: The original fizz-buzz consists in writing all numbers from 1 to 100, and just replacing all multiples of 3 by "fizz", all multiples of 5 by "buzz", and all multiples of 15 by "fizzbuzz". The output would look like this: "1,2,fizz,4,buzz,fizz,7,8,fizz,buzz,11,fizz,13,14,fizzbuzz,16,...".

The REST Server building with C++ and REST framework Oatpp.

## Prerequisite

If you test with local installation:  Make sure you have some C++ complier, cmake and docker installed. Data is stored with PostgreSQL, so you're gonna need it installed too.

The project is using following oatpp modules (with install instructions) :

- [oatpp](https://github.com/oatpp/oatpp) 
- [oatpp-swagger](https://github.com/oatpp/oatpp-swagger)
- [oatpp-postgresql](https://github.com/oatpp/oatpp-postgresql)


## Usage

Get list of FizzBuzz strings:
```Curl
curl -X GET "http://localhost:8000/fizzbuzz/int1/3/int2/6/str1/F/str2/B/limit/30" -H  "accept: application/json"
```

Get stats:
```Curl
curl -X GET "http://localhost:8000/stats" -H  "accept: application/json"
```

Or you can use the swagger interface at:

```Swagger
http://localhost:8000/swagger/ui#/default/
```


## Install 

```
    git clone git@github.com:Schierke/fizzbuzz-cpp.git
```

### Local install

```
mkdir build && cd build
cmake..
make
```

> Then go to `resources\config.json`, under `dev` section, change `dbConnectionString` to the URI of your PostgreSQL local configuration 

#### Execution

To run application: 
```
    ./fizzbuzz-cpp-exe
```

To lauch Unit test: 

```
    fizzbuzz-cpp-test
```

### Docker

Simpler way to run application:
```
    docker-compose up
```
* Docker-compose will run service with `local-docker` configuration

