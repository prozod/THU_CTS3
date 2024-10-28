DELIMITER //

DROP PROCEDURE IF EXISTS `generate_driver_statistics`//

CREATE PROCEDURE generate_driver_statistics(IN iYear INT, IN week_of_the_year INT)
BEGIN
    CREATE TABLE IF NOT EXISTS DriverRecords(
        `Year` INT,  
        Week INT, 
        DriverId INT,
        NumOfBookings INT DEFAULT 0,
        FOREIGN KEY (DriverId) REFERENCES Driver(idDriver),
		UNIQUE (DriverId, `Year`, Week)
    );
    
    INSERT INTO DriverRecords (DriverId, `Year`, Week, NumOfBookings)
    SELECT 
        b.Driver_idDriver, 
        YEAR(b.BookingTime) AS `Year`, 
        WEEK(b.BookingTime) AS Week,
        COUNT(b.idBooking) AS NumOfBookings
    FROM 
        Booking b
    WHERE 
        YEAR(b.BookingTime) = iYear
        AND WEEK(b.BookingTime) = week_of_the_year
    GROUP BY 
        b.Driver_idDriver, WEEK(b.BookingTime), YEAR(b.BookingTime)
	ON DUPLICATE KEY UPDATE
        NumOfBookings = VALUES(NumOfBookings); 
    
END //

DELIMITER ;
