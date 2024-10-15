-- Create a function that converts a date in MySQL format (YYYY-MM-DD) to German format (DD.MM.YYYY) using SUBSTRING()
DELIMITER $$

DROP FUNCTION IF EXISTS date_conversion$$

CREATE FUNCTION date_conversion(`date` DATE)
RETURNS VARCHAR(10)
DETERMINISTIC 
BEGIN
	DECLARE german_date VARCHAR(10);
    SELECT CONCAT(SUBSTRING(`date`, -2), '.', SUBSTRING(`date`, 6, 2), '.', SUBSTRING(`date`, 1, 4)) INTO german_date;
	RETURN german_date;
END$$
DELIMITER ;