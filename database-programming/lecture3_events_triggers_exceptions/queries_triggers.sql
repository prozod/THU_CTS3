INSERT INTO `ORDER` (CUSTOMER_ID, ADDRESS_ID, ORDER_DATE, STATUS, DELETED) VALUES (2, 2, CURDATE(), 'SHIPPED', 0); -- check if trigger creates an invoice too 
DELETE FROM `ORDER` WHERE ORDER_ID = 11; -- check if trigger deletes invoice too

SELECT * FROM `ORDER` WHERE CUSTOMER_ID = 2;
SELECT * FROM INVOICE i JOIN `ORDER` o ON i.ORDER_ID = o.ORDER_ID WHERE o.CUSTOMER_ID = 2; 

SHOW COLUMNS FROM `ORDER`;
SHOW COLUMNS FROM INVOICE;
