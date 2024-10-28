DELIMITER //
CREATE PROCEDURE turnover_report
(IN i_TimeInterval INT )
BEGIN
	CASE i_TimeInterval
		WHEN 1 THEN -- Total
			DROP TABLE IF EXISTS TurnoverFiguresTotal;
			CREATE TABLE TurnoverFiguresTotal
			SELECT 'Total', SUM(PRICE * AMOUNT) AS `Turnover`
			FROM INVOICE_POSITION INNER JOIN ARTICLE USING (ARTICLE_ID)
			INNER JOIN INVOICE USING (INVOICE_ID);
		WHEN 2 THEN -- Per Year
			DROP TABLE IF EXISTS TurnoverFiguresYear;
			CREATE TABLE TurnoverFiguresYear
			SELECT YEAR(INVOICE_DATE) AS `YEAR`, SUM(PRICE * AMOUNT) AS `Turnover`
			FROM INVOICE_POSITION INNER JOIN ARTICLE USING (ARTICLE_ID)
			INNER JOIN INVOICE USING (INVOICE_ID)
			GROUP BY `YEAR`
			ORDER BY `YEAR` DESC;
		WHEN 3 THEN -- Per Month
			DROP TABLE IF EXISTS TurnoverFiguresMonth;
			CREATE TABLE TurnoverFiguresMonth
			SELECT YEAR(INVOICE_DATE) AS `YEAR`, MONTH(INVOICE_DATE) AS `MONTH`, SUM(PRICE * AMOUNT) AS `Turnover`
			FROM INVOICE_POSITION INNER JOIN ARTICLE USING (ARTICLE_ID)
			INNER JOIN INVOICE USING (INVOICE_ID)
			GROUP BY `YEAR`, `MONTH`
			ORDER BY `YEAR` DESC, `MONTH` DESC;
		ELSE -- Otherwise
			CREATE TABLE TurnoverFigures
			SELECT 'Unknown Report', i_TimeInterval;
		END CASE;
END//