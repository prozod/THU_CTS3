SET AUTOCOMMIT = 0;
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SELECT @@global.transaction_isolation, @@transaction_isolation;

SELECT * FROM ADDRESS;

UPDATE ADDRESS
SET POSTAL_CODE = 4408
WHERE ADDRESS_ID = 2;

UPDATE ADDRESS
SET POSTAL_CODE = 2517
WHERE ADDRESS_ID = 1;


