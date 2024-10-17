-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE year = 2024
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street';

SELECT name, transcript
FROM interviews
WHERE year = 2024
  AND month = 7
  AND day = 28;

SELECT name
FROM people
WHERE name = 'Eugene';

SELECT name, transcript
FROM interviews
WHERE year = 2024
  AND month = 7
  AND day = 28
  AND transcript LIKE '%bakery%'
ORDER BY name;

SELECT account_number, amount
FROM atm_transactions
WHERE year = 2024
  AND month = 7
  AND day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';

SELECT name, atm_transactions.amount
FROM people
JOIN bank_accounts
  ON people.id = bank_accounts.person_id
JOIN atm_transactions
  ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2024
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_transactions.atm_location = 'Leggett Street'
  AND atm_transactions.transaction_type = 'withdraw';

SELECT abbreviation, full_name, city
FROM airports
WHERE city = 'Fiftyville';

SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights
  ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id =
      (SELECT id
         FROM airports
        WHERE city = 'Fiftyville')
  AND flights.year = 2024
  AND flights.month = 7
  AND flights.day = 29
ORDER BY flights.hour, flights.minute;

SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
  ON people.passport_number = passengers.passport_number
JOIN flights
  ON passengers.flight_id = flights.id
WHERE flights.year = 2024
  AND flights.month = 7
  AND flights.day = 29
  AND flights.hour = 8
  AND flights.minute = 20
ORDER BY passengers.passport_number;

SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
  ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2024
  AND phone_calls.month = 7
  AND phone_calls.day = 28
  AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;

SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
  ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2024
  AND phone_calls.month = 7
  AND phone_calls.day = 28
  AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;

SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
JOIN bakery_security_logs
  ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2024
  AND bakery_security_logs.month = 7
  AND bakery_security_logs.day = 28
  AND bakery_security_logs.activity = 'exit'
  AND bakery_security_logs.hour = 10
  AND bakery_security_logs.minute >= 15
  AND bakery_security_logs.minute <= 25
ORDER BY bakery_security_logs.minute;

SELECT *
FROM crime_scene_reports
WHERE street = "Humphrey Street" AND year = 2021 AND month = 7 AND day = 28;

SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE activity = "exit" AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 40
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
)
AND people.id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE bank_accounts.account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"
    )
);

SELECT *
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller IN ("(286) 555-6063", "(770) 555-1861", "(367) 555-5533")
);

SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
AND caller IN ("(286) 555-6063", "(770) 555-1861", "(367) 555-5533")
AND receiver IN ("(676) 555-6554", "(725) 555-3243", "(375) 555-8161");

SELECT *
FROM flights
JOIN airports
ON airports.id = flights.origin_airport_id
WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour BETWEEN 00 AND 12 AND airports.city = "Fiftyville"
ORDER BY flights.hour, flights.minute;

SELECT full_name, city
FROM airports
WHERE id IN (1, 4, 11);

SELECT name, passport_number
FROM people
WHERE people.name IN ("Bruce", "Taylor", "Diana", "James", "Philip", "Robin")
AND passport_number IN (
    SELECT passport_number
    FROM passengers
    JOIN flights
    ON flights.id = passengers.flight_id
    JOIN airports
    ON airports.id = flights.origin_airport_id
    WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour BETWEEN 00 AND 12
    AND flights.origin_airport_id IN (
        SELECT airports.id
        FROM airports
        WHERE airports.city = "Fiftyville"
    )
    AND flights.destination_airport_id IN (
        SELECT airports.id
        FROM airports
        WHERE airports.city IN ("New York City", "Chicago", "San Francisco")
    )
);

SELECT full_name, city, passport_number, flights.destination_airport_id, flights.hour, flights.minute
FROM airports
JOIN flights
ON flights.origin_airport_id = airports.id
JOIN passengers
ON passengers.flight_id = flights.id
WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND hour BETWEEN 00 AND 12
AND passengers.passport_number IN (
    SELECT passport_number
    FROM people
    WHERE people.name IN ("Bruce", "Taylor", "Diana", "James", "Philip", "Robin")
);
