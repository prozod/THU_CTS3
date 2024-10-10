SET AUTOCOMMIT = 0;
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SELECT @@global.transaction_isolation, @@transaction_isolation;

UPDATE ADDRESS
SET POSTAL_CODE = 2517
WHERE ADDRESS_ID = 1;

UPDATE ADDRESS
SET POSTAL_CODE = 4408
WHERE ADDRESS_ID = 2;

SELECT * FROM ADDRESS WHERE ADDRESS_ID = 2; -- SELECT introduces deadlock (locking read) if queried after UPDATE in session 1
