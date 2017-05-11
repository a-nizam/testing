/*
Navicat PGSQL Data Transfer

Source Server         : testing
Source Server Version : 90602
Source Host           : localhost:5432
Source Database       : testing
Source Schema         : public

Target Server Type    : PGSQL
Target Server Version : 90602
File Encoding         : 65001

Date: 2017-05-11 11:31:02
*/


-- ----------------------------
-- Sequence structure for answer_ans_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "answer_ans_id_seq";
CREATE SEQUENCE "answer_ans_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 12
 CACHE 1;
SELECT setval('"public"."answer_ans_id_seq"', 12, true);

-- ----------------------------
-- Sequence structure for question_q_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "question_q_id_seq";
CREATE SEQUENCE "question_q_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 5
 CACHE 1;
SELECT setval('"public"."question_q_id_seq"', 5, true);

-- ----------------------------
-- Sequence structure for question_type_qtype_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "question_type_qtype_id_seq";
CREATE SEQUENCE "question_type_qtype_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 3
 CACHE 1;
SELECT setval('"public"."question_type_qtype_id_seq"', 3, true);

-- ----------------------------
-- Sequence structure for student_student_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "student_student_id_seq";
CREATE SEQUENCE "student_student_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 4
 CACHE 1;
SELECT setval('"public"."student_student_id_seq"', 4, true);

-- ----------------------------
-- Sequence structure for subject_sub_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "subject_sub_id_seq";
CREATE SEQUENCE "subject_sub_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 2
 CACHE 1;
SELECT setval('"public"."subject_sub_id_seq"', 2, true);

-- ----------------------------
-- Sequence structure for test_test_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "test_test_id_seq";
CREATE SEQUENCE "test_test_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 3
 CACHE 1;
SELECT setval('"public"."test_test_id_seq"', 3, true);

-- ----------------------------
-- Sequence structure for theme_thm_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "theme_thm_id_seq";
CREATE SEQUENCE "theme_thm_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 8
 CACHE 1;
SELECT setval('"public"."theme_thm_id_seq"', 8, true);

-- ----------------------------
-- Sequence structure for ticket_tic_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "ticket_tic_id_seq";
CREATE SEQUENCE "ticket_tic_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 1
 CACHE 1;

-- ----------------------------
-- Sequence structure for ticket_type_ttype_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "ticket_type_ttype_id_seq";
CREATE SEQUENCE "ticket_type_ttype_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 2
 CACHE 1;
SELECT setval('"public"."ticket_type_ttype_id_seq"', 2, true);

-- ----------------------------
-- Sequence structure for user_id_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "user_id_seq";
CREATE SEQUENCE "user_id_seq"
 INCREMENT 1
 MINVALUE 1
 MAXVALUE 9223372036854775807
 START 3
 CACHE 1;
SELECT setval('"public"."user_id_seq"', 3, true);

-- ----------------------------
-- Table structure for answer
-- ----------------------------
DROP TABLE IF EXISTS "answer";
CREATE TABLE "answer" (
"ans_id" int4 DEFAULT nextval('answer_ans_id_seq'::regclass) NOT NULL,
"ans_content" varchar(511) COLLATE "default" NOT NULL,
"ans_question" int4 NOT NULL,
"ans_is_correct" bool NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of answer
-- ----------------------------
BEGIN;
INSERT INTO "answer" VALUES ('1', 'Ответ на вопрос 1', '1', 'f');
INSERT INTO "answer" VALUES ('2', 'ответ на вопрос 10', '3', 'f');
INSERT INTO "answer" VALUES ('3', 'Ответ на вопрос 1_', '1', 'f');
INSERT INTO "answer" VALUES ('7', 'Ответ на вопрос 1_', '1', 't');
INSERT INTO "answer" VALUES ('9', 'Ответ на вопрос 2', '2', 'f');
INSERT INTO "answer" VALUES ('11', 'ответ 1', '4', 't');
INSERT INTO "answer" VALUES ('12', 'ответ 2', '4', 'f');
COMMIT;

-- ----------------------------
-- Table structure for question
-- ----------------------------
DROP TABLE IF EXISTS "question";
CREATE TABLE "question" (
"q_id" int4 DEFAULT nextval('question_q_id_seq'::regclass) NOT NULL,
"q_content" varchar(511) COLLATE "default" NOT NULL,
"q_theme" int4 NOT NULL,
"q_type" int4 NOT NULL,
"q_no_variants" bool NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of question
-- ----------------------------
BEGIN;
INSERT INTO "question" VALUES ('1', 'Вопрос 1', '1', '1', 'f');
INSERT INTO "question" VALUES ('2', 'Вопрос 2', '1', '2', 'f');
INSERT INTO "question" VALUES ('3', 'Вопрос 10', '7', '2', 'f');
INSERT INTO "question" VALUES ('4', 'Текст вопроса', '1', '3', 'f');
INSERT INTO "question" VALUES ('5', 'Текст вопроса', '1', '2', 'f');
COMMIT;

-- ----------------------------
-- Table structure for question_type
-- ----------------------------
DROP TABLE IF EXISTS "question_type";
CREATE TABLE "question_type" (
"qtype_id" int4 DEFAULT nextval('question_type_qtype_id_seq'::regclass) NOT NULL,
"qtype_name" varchar(15) COLLATE "default" NOT NULL,
"qtype_ticket_type" int4 NOT NULL,
"qtype_cost" int4 NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of question_type
-- ----------------------------
BEGIN;
INSERT INTO "question_type" VALUES ('1', 'Простой', '1', '1');
INSERT INTO "question_type" VALUES ('2', 'Средний', '1', '3');
INSERT INTO "question_type" VALUES ('3', 'Сложный', '1', '5');
COMMIT;

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS "student";
CREATE TABLE "student" (
"student_id" int4 DEFAULT nextval('student_student_id_seq'::regclass) NOT NULL,
"student_fname" varchar(500) COLLATE "default" NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of student
-- ----------------------------
BEGIN;
INSERT INTO "student" VALUES ('1', 'Magomed');
INSERT INTO "student" VALUES ('2', 'Murad');
INSERT INTO "student" VALUES ('3', 'Islam');
INSERT INTO "student" VALUES ('4', 'Gadjimurad');
COMMIT;

-- ----------------------------
-- Table structure for subject
-- ----------------------------
DROP TABLE IF EXISTS "subject";
CREATE TABLE "subject" (
"sub_id" int4 DEFAULT nextval('subject_sub_id_seq'::regclass) NOT NULL,
"sub_name" varchar(63) COLLATE "default" NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of subject
-- ----------------------------
BEGIN;
INSERT INTO "subject" VALUES ('1', 'Химия');
INSERT INTO "subject" VALUES ('2', 'Биология');
COMMIT;

-- ----------------------------
-- Table structure for test
-- ----------------------------
DROP TABLE IF EXISTS "test";
CREATE TABLE "test" (
"test_id" int4 DEFAULT nextval('test_test_id_seq'::regclass) NOT NULL,
"test_ticket_type" int4 NOT NULL,
"test_date" date NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of test
-- ----------------------------
BEGIN;
INSERT INTO "test" VALUES ('1', '1', '2017-05-04');
INSERT INTO "test" VALUES ('2', '1', '2017-05-02');
INSERT INTO "test" VALUES ('3', '2', '2017-05-06');
COMMIT;

-- ----------------------------
-- Table structure for theme
-- ----------------------------
DROP TABLE IF EXISTS "theme";
CREATE TABLE "theme" (
"thm_id" int4 DEFAULT nextval('theme_thm_id_seq'::regclass) NOT NULL,
"thm_name" varchar(63) COLLATE "default" NOT NULL,
"thm_ttype" int4 NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of theme
-- ----------------------------
BEGIN;
INSERT INTO "theme" VALUES ('1', 'Тема 1', '1');
INSERT INTO "theme" VALUES ('4', 'Тема 2', '2');
INSERT INTO "theme" VALUES ('5', 'Тема 3 биология', '2');
INSERT INTO "theme" VALUES ('6', 'Тема 4 биология', '2');
INSERT INTO "theme" VALUES ('7', 'Тема 2 Химия', '1');
INSERT INTO "theme" VALUES ('8', 'Вопрос 2', '1');
COMMIT;

-- ----------------------------
-- Table structure for ticket
-- ----------------------------
DROP TABLE IF EXISTS "ticket";
CREATE TABLE "ticket" (
"tic_id" int4 DEFAULT nextval('ticket_tic_id_seq'::regclass) NOT NULL,
"tic_ttype" int4 NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of ticket
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for ticket_type
-- ----------------------------
DROP TABLE IF EXISTS "ticket_type";
CREATE TABLE "ticket_type" (
"ttype_id" int4 DEFAULT nextval('ticket_type_ttype_id_seq'::regclass) NOT NULL,
"ttype_name" varchar(31) COLLATE "default" NOT NULL,
"ttype_subject" int4 NOT NULL
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of ticket_type
-- ----------------------------
BEGIN;
INSERT INTO "ticket_type" VALUES ('1', 'Тест по химии', '1');
INSERT INTO "ticket_type" VALUES ('2', 'Тест по биологии', '2');
COMMIT;

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS "users";
CREATE TABLE "users" (
"id" int4 DEFAULT nextval('user_id_seq'::regclass) NOT NULL,
"fname" varchar(255) COLLATE "default"
)
WITH (OIDS=FALSE)

;

-- ----------------------------
-- Records of users
-- ----------------------------
BEGIN;
INSERT INTO "users" VALUES ('1', 'Nizam');
INSERT INTO "users" VALUES ('2', 'Tima');
INSERT INTO "users" VALUES ('3', 'Mevlud');
COMMIT;

-- ----------------------------
-- Alter Sequences Owned By 
-- ----------------------------
ALTER SEQUENCE "answer_ans_id_seq" OWNED BY "answer"."ans_id";
ALTER SEQUENCE "question_q_id_seq" OWNED BY "question"."q_id";
ALTER SEQUENCE "question_type_qtype_id_seq" OWNED BY "question_type"."qtype_id";
ALTER SEQUENCE "student_student_id_seq" OWNED BY "student"."student_id";
ALTER SEQUENCE "subject_sub_id_seq" OWNED BY "subject"."sub_id";
ALTER SEQUENCE "test_test_id_seq" OWNED BY "test"."test_id";
ALTER SEQUENCE "theme_thm_id_seq" OWNED BY "theme"."thm_id";
ALTER SEQUENCE "ticket_tic_id_seq" OWNED BY "ticket"."tic_id";
ALTER SEQUENCE "ticket_type_ttype_id_seq" OWNED BY "ticket_type"."ttype_id";
ALTER SEQUENCE "user_id_seq" OWNED BY "users"."id";

-- ----------------------------
-- Primary Key structure for table answer
-- ----------------------------
ALTER TABLE "answer" ADD PRIMARY KEY ("ans_id");

-- ----------------------------
-- Primary Key structure for table question
-- ----------------------------
ALTER TABLE "question" ADD PRIMARY KEY ("q_id");

-- ----------------------------
-- Primary Key structure for table question_type
-- ----------------------------
ALTER TABLE "question_type" ADD PRIMARY KEY ("qtype_id");

-- ----------------------------
-- Primary Key structure for table student
-- ----------------------------
ALTER TABLE "student" ADD PRIMARY KEY ("student_id");

-- ----------------------------
-- Primary Key structure for table subject
-- ----------------------------
ALTER TABLE "subject" ADD PRIMARY KEY ("sub_id");

-- ----------------------------
-- Primary Key structure for table test
-- ----------------------------
ALTER TABLE "test" ADD PRIMARY KEY ("test_id");

-- ----------------------------
-- Primary Key structure for table theme
-- ----------------------------
ALTER TABLE "theme" ADD PRIMARY KEY ("thm_id");

-- ----------------------------
-- Primary Key structure for table ticket
-- ----------------------------
ALTER TABLE "ticket" ADD PRIMARY KEY ("tic_id");

-- ----------------------------
-- Primary Key structure for table ticket_type
-- ----------------------------
ALTER TABLE "ticket_type" ADD PRIMARY KEY ("ttype_id");
