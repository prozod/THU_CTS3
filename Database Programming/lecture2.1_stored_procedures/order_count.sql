/* Create a stored procedure that groups every customer (incl. those who have not yet ordered)
according to the number of orders they have placed into groups A, B and C. The thresholds should be passed using parameters.
- Customers having limit_1 or more orders belong to class A
- Customers having between limit_2 and limit_1 - 1 orders belong to class B
- All other customers belong to group C */

USE thisandthat;
DELIMITER $$
DROP PROCEDURE IF EXISTS order_count$$
CREATE PROCEDURE order_count(IN limit_1 INT, IN limit_2 INT)
BEGIN 
	WITH CUSTOMER_ORDERS AS 
    (
	SELECT c.LASTNAME, c.FIRSTNAME, COUNT(o.ORDER_ID) as order_count
	FROM CUSTOMER c
	LEFT JOIN `ORDER` o ON c.CUSTOMER_ID = o.CUSTOMER_ID
	GROUP BY c.CUSTOMER_ID
    ) 
    SELECT co.FIRSTNAME, co.LASTNAME,
    CASE
		WHEN co.order_count >= limit_1 THEN 'A'
        WHEN co.order_count BETWEEN limit_2 AND limit_1 - 1 THEN 'B'
        ELSE 'C'
	END AS GROUP_NAME
    FROM
		CUSTOMER_ORDERS co;
END$$
DELIMITER ;