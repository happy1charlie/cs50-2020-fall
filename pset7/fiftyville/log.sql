-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Search crime scene report for description
SELECT street, description FROM crime_scene_reports WHERE year = "2020" AND month = 7 AND day = "28" AND street LIKE "%Chamberlin Street%";

-- Search interviews for transcript of courthouse
SELECT id, transcript FROM interviews WHERE  year = "2020" AND month = 7 AND day = "28" AND transcript LIKE "%courthouse%";

-- Search courthouse_security_logs on 2020 JULY 28
SELECT license_plate FROM courthouse_security_logs WHERE year = "2020" AND month = 7 AND day = "28" AND hour = "10" AND minute > 15 AND minute < 20;

-- Search people for license_plate
SELECT name FROM people WHERE people.license_plate IN
(SELECT courthouse_security_logs.license_plate FROM courthouse_security_logs WHERE year = "2020" AND month = 7 AND day = "28" AND hour = "10" AND 20 > minute > 15);
