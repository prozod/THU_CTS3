CALL TEST_create_transactional_order(3, 3);

SELECT * FROM `ORDER` WHERE CUSTOMER_ID=3;
SELECT * FROM INVOICE WHERE ORDER_ID=13;

DELETE FROM `ORDER` WHERE ORDER_ID=13;