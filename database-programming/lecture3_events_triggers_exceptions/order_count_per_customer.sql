DELIMITER $$

DROP FUNCTION IF EXISTS order_count_per_customer$$

CREATE FUNCTION order_count_per_customer(customerId INT, lim1 INT, lim2 INT) 
RETURNS CHAR(1)
DETERMINISTIC
BEGIN
    DECLARE order_count INT;
    
    SELECT COUNT(o.ORDER_ID) INTO order_count
    FROM `ORDER` o
    WHERE o.CUSTOMER_ID = customerId;
    
    IF order_count >= lim1 THEN
        RETURN 'A';
    ELSEIF order_count BETWEEN lim2 AND lim1 - 1 THEN
        RETURN 'B';
    ELSE
        RETURN 'C';
    END IF;
END$$

DELIMITER ;
