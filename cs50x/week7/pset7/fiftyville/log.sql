-- Keep a log of any SQL queries you execute as you solve the mystery.

-- * hints: All you know is that the theft took place on July 28, 2023 and that it took place on Humphrey Street.

-- TODO: first check the crime_scene_reports for reports that happened on July 28 2023 and Humphrey Ave
SELECT * FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street LIKE 'Humphrey%';
-- ? id: 295
-- ? description: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- TODO: check interviews
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;
-- ? Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- ? Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- ? Lily: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- TODO: check bakery security logs
sqlite> SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;
-- ? sometime within 10 minutes meaning 10:15 to 10:25
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+-----+------+-------+-----+------+--------+----------+---------------+

-- TODO: check phone calls for calls less than 60 seconds
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+

-- TODO: check atm at Legett Street for withdrawals on 28 July 2023
SELECT * FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

-- TODO: check earliest flight out of Fiftyville on 29th July 2023
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC;
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
| 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
| 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
| 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |
+----+-------------------+------------------------+------+-------+-----+------+--------+
-- ? The earliest flight out of Fiftyville on 29th July 2023 is 8.20am from airport 8 to airport 4 (Fiftyville to LaGuardia)
SELECT * FROM airports WHERE id = 8 OR id = 4
+----+--------------+-----------------------------+---------------+
| id | abbreviation |          full_name          |     city      |
+----+--------------+-----------------------------+---------------+
| 4  | LGA          | LaGuardia Airport           | New York City |
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville    |
+----+--------------+-----------------------------+---------------+

-- TODO: check passengers to see if they line up with the suspected phone calls, license plates, atm accounts
SELECT * FROM people
WHERE phone_number IN
    (
    SELECT caller FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60
    )
AND passport_number IN
    (
    SELECT passport_number FROM passengers
    WHERE flight_id IN
        (
            SELECT id FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC LIMIT 1
        )
    )
AND id IN
    (
        SELECT person_id FROM bank_accounts
        WHERE account_number IN
            (
                SELECT account_number FROM atm_transactions
                WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
            )
    )
AND license_plate IN
    (
        SELECT license_plate FROM bakery_security_logs
        WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
    );

+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+
-- ? Bruce is the suspected thief. Now we can start to find the accomplice using the call logs

SELECT * FROM people
WHERE phone_number IN
    (
        SELECT receiver FROM phone_calls
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533'
    );
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+

-- ? Robin is the suspected accomplice.

