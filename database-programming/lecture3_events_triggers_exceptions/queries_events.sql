SET GLOBAL event_scheduler = ON;
SHOW VARIABLES LIKE 'event%';

CREATE EVENT CalculateYearlyTurnover
ON SCHEDULE EVERY 1 YEAR
STARTS CURRENT_TIMESTAMP + INTERVAL 1 YEAR
DO
    CALL turnover_report(2);
    
CREATE EVENT CalculateMonthlyTurnover
ON SCHEDULE EVERY 1 MONTH
STARTS CURRENT_TIMESTAMP + INTERVAL 1 MONTH
DO
    CALL turnover_report(3);
    
SHOW EVENTS;