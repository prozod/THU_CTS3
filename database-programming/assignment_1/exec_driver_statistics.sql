SET GLOBAL event_scheduler = ON;
SHOW VARIABLES LIKE 'event%';

CREATE EVENT exec_driver_statistics
ON SCHEDULE EVERY 1 WEEK
STARTS '2019-10-28  00:00:00' + INTERVAL 1 WEEK
DO
    CALL generate_driver_statistics(2019, 22);
    
SHOW EVENTS;