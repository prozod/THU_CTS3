use thisandthat;
SET AUTOCOMMIT = 0;
SET SESSION TRANSACTION ISOLATION
LEVEL REPEATABLE READ;

SELECT @@global.transaction_isolation; -- global
SELECT @@transaction_isolation;        -- session

SELECT * FROM ARTICLE;
UPDATE ARTICLE SET PRICE=5.00 WHERE ARTICLE = 'Pick';