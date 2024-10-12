USE thisandthat2;
DELIMITER $$

DROP PROCEDURE IF EXISTS delete_order_pos$$

CREATE PROCEDURE delete_order_pos(IN prod_order_id INT, IN prod_art_id INT)
BEGIN
    DECLARE new_position_nr INT DEFAULT 1;
    
	DELETE FROM INVOICE_POSITION
    WHERE INVOICE_ID = prod_order_id
    AND ARTICLE_ID = prod_art_id;

    DELETE FROM ORDER_POSITION 
    WHERE ORDER_ID = prod_order_id 
    AND ARTICLE_ID = prod_art_id;
    
    SET @new_position_nr = 0;  

    UPDATE ORDER_POSITION
    SET POSITION_NR = (@new_position_nr := @new_position_nr + 1)
    WHERE ORDER_ID = prod_order_id
    ORDER BY POSITION_NR;
    
	UPDATE INVOICE_POSITION ip
    JOIN ORDER_POSITION op
        ON ip.INVOICE_ID = op.ORDER_ID
    SET ip.POSITION_NR = op.POSITION_NR
    WHERE ip.INVOICE_ID = 1;
END$$
DELIMITER ; 
