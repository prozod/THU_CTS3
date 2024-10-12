/* Create a procedure for the generic version of task 1 (insert a new article).
TIPS:
- All parameters should be IN parameters
- Of course only one article group can be passed
- Check if the article group exists using branching
- Remember the procedure can be executed using CALL procedure_name;
- Mind the DELIMITER problem */

USE thisandthat;
DELIMITER $$
DROP PROCEDURE IF EXISTS insert_article$$ -- remove because there is no such thing as "ALTER"-ing a procedure, you delete old one then create it again.
CREATE PROCEDURE insert_article(IN ARTNAME VARCHAR(255), IN ARTPRICE DECIMAL (6,2), IN ARTCURRENCY CHAR(3), IN ARTGROUP VARCHAR(255))
BEGIN
	DECLARE ART_ID INT;
    DECLARE ARTGROUP_ID INT;
    
    INSERT INTO ARTICLE (ARTICLE, PRICE, CURRENCY) VALUES (ARTNAME, ARTPRICE, ARTCURRENCY);
    SELECT LAST_INSERT_ID() INTO ART_ID;
	SELECT ARTICLEGROUP_ID FROM ARTICLEGROUP WHERE ARTICLEGROUP = ARTGROUP INTO ARTGROUP_ID;
    
    IF ARTGROUP_ID IS NULL THEN
    INSERT INTO ARTICLEGROUP VALUES (NULL, ARTGROUP, 0);
    SET ARTGROUP_ID = LAST_INSERT_ID();
    END IF;
    
    INSERT INTO ARTICLE_NM_ARTICLEGROUP (ARTICLEGROUP_ID, ARTICLE_ID) VALUES (ARTGROUP_ID, ART_ID);
END$$
DELIMITER ;