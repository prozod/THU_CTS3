-- USING THE GIVEN VIEW (given in the assigment)
CREATE VIEW travel_statistic AS
SELECT c.idCustomer, c.Surname, c.Firstname, SUM(b.DistanceInKM) AS SumDistance
FROM  Customer c 
JOIN Booking b ON b.Customer_idCustomer = c.idCustomer
GROUP BY c.idCustomer;

DELIMITER //
CREATE FUNCTION customer_class(customer_id INT) RETURNS CHAR(1)
DETERMINISTIC
BEGIN
  DECLARE customer_group CHAR(1);
  SELECT 
    CASE
      WHEN ts.SumDistance >= 0.85 * (SELECT MAX(SumDistance) FROM travel_statistic) THEN 'A'
      WHEN ts.SumDistance >= 0.40 * (SELECT AVG(SumDistance) FROM travel_statistic) THEN 'B'
      ELSE 'C'
    END
  INTO customer_group
  FROM travel_statistic ts
  WHERE ts.idCustomer = customer_id;

  RETURN customer_group;
END //
DELIMITER ;

SELECT idCustomer, Surname, Firstname, customer_class(idCustomer) AS CustomerGroup
FROM travel_statistic
WHERE idCustomer = 19;

SELECT idCustomer, Surname, Firstname, customer_class(idCustomer) AS CustomerGroup FROM travel_statistic;