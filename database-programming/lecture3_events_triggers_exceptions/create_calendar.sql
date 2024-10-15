USE thisandthat;
DELIMITER $$
DROP PROCEDURE IF EXISTS create_calendar$$

CREATE PROCEDURE create_calendar(IN year INT) 
BEGIN
	DECLARE starting_date DATE;
    DECLARE ending_date DATE;
	DECLARE EXIT HANDLER FOR SQLEXCEPTION 
    BEGIN
		SELECT `Rollback executed!`;
		ROLLBACK;
    END;
	
	DROP TABLE IF EXISTS CALENDAR;
    
    START TRANSACTION;

	CREATE TABLE CALENDAR(DATEOFDAY Date, DAYOFYEAR int, DAYNAME VARCHAR(10), CALENDARWEEK TINYINT);
    
    SET starting_date = DATE_FORMAT(CONCAT(year, '-01-01'), '%Y-%m-%d');
    SET ending_date = DATE_FORMAT(CONCAT(year + 1, '-01-01'), '%Y-%m-%d');
    
    WHILE starting_date < ending_date DO
		INSERT INTO CALENDAR (DATEOFDAY, DAYOFYEAR, DAYNAME, CALENDARWEEK)
		VALUES (starting_date, DAYOFYEAR(starting_date), DAYNAME(starting_date), WEEK(starting_date, 1));

		SET starting_date = DATE_ADD(starting_date, INTERVAL 1 DAY);
    END WHILE;
    
    COMMIT;
END$$
DELIMITER ;