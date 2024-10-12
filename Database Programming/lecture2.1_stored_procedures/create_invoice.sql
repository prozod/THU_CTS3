-- Create a procedure that creates an invoice for an order id given (incl. positions). It must be
-- checked if an invoice for the order already exists. (values can be copied from order table)

USE thisandthat;
DELIMITER $$
DROP PROCEDURE IF EXISTS create_invoice$$

CREATE PROCEDURE create_invoice(IN ORD_ID INT)
BEGIN
	DECLARE ORDER_STATUS INT; -- 0 daca nu exista (count)
    DECLARE NEW_INVOICE_ID INT;
    
    SET ORDER_STATUS = (SELECT COUNT(*) FROM `ORDER` o
    LEFT JOIN INVOICE i ON o.ORDER_ID = i.ORDER_ID
    WHERE o.ORDER_ID = ORD_ID AND i.INVOICE_ID IS NULL);

    IF (ORDER_STATUS > 0) 
    THEN
		-- creezi un invoice, preiau ID-ul 
		-- pe urma pt. fiecare articol care apartine comenzii, faci un invoice position si il atasezi INVOICE-ului
        INSERT INTO INVOICE (ORDER_ID, PAYMENT_TYPE, STATUS, INVOICE_DATE, DISCOUNT, SKONTO, DELETED)
        VALUES (ORD_ID, 'CREDITCARD', 'OPEN', CURRENT_TIMESTAMP(), 5.00, 5.00, 0);
        
		SET NEW_INVOICE_ID = LAST_INSERT_ID();
         
		SET @row_num = 0;
        
        INSERT INTO INVOICE_POSITION (INVOICE_ID, POSITION_NR, ARTICLE_ID, AMOUNT)
        SELECT NEW_INVOICE_ID, (@row_num := @row_num + 1) AS POSITION_NR, a.ARTICLE_ID, op.AMOUNT
        FROM ORDER_POSITION op
        JOIN ARTICLE a ON op.ARTICLE_ID = a.ARTICLE_ID
        WHERE op.ORDER_ID = ORD_ID;
	ELSE 
		SELECT 'Invoice for that order already exists.';
    END IF;
END$$
DELIMITER ;