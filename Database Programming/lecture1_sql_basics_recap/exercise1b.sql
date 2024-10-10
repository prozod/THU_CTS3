-- Select all customers which are of type ‘BUSINESS’
SELECT * 
FROM CUSTOMER c 
WHERE c.CUSTOMER_TYPE = 'BUSINESS';


-- Select the remaining customers which did not appear in the result set of No 1 and only select LASTNAME, FIRSTNAME and SALUTATION
SELECT c.LASTNAME, c.FIRSTNAME, c.SALUTATION
FROM CUSTOMER c
WHERE c.CUSTOMER_TYPE <> 'BUSINESS';
    
   
-- Select customers that have a city starting with ‘A’ in their delivery address and customers that have a city starting with ‘B’ in their delivery address.
SELECT c.FIRSTNAME, c.LASTNAME
FROM CUSTOMER c 
JOIN ADDRESS a ON c.DELIVERY_ADDRESS_ID = a.ADDRESS_ID 
WHERE a.CITY LIKE 'A%' OR a.CITY LIKE 'B%'

-- Select the customers along with the name of their bank.
SELECT c.FIRSTNAME, c.LASTNAME, b.BANK 
FROM CUSTOMER c
JOIN BANK b ON c.CUSTOMER_ID = b.BANK_ID

-- Count the number of banks that each customer has
-- -- Develop the previous exercise above further and exclude customers that only have one single bank assigned.
SELECT c.FIRSTNAME, c.LASTNAME, b.BANK, COUNT(DISTINCT b.BANK_ID) as NUMOFBANKS
FROM CUSTOMER c
JOIN BANK b ON c.CUSTOMER_ID = b.BANK_ID
GROUP BY c.CUSTOMER_ID, c.FIRSTNAME, c.LASTNAME, b.BANK
HAVING COUNT(DISTINCT b.BANK_ID) > 1

-- Select all invoices of Mrs. Dunn and compute the total sum per invoice.
SELECT i.INVOICE_ID, SUM(ip.AMOUNT * a.PRICE) AS TOTAL_SUM 
FROM INVOICE i 
JOIN INVOICE_POSITION ip ON i.INVOICE_ID =ip.INVOICE_ID 
JOIN ARTICLE a ON ip.ARTICLE_ID = a.ARTICLE_ID 
JOIN `ORDER` o ON i.ORDER_ID = o.ORDER_ID
JOIN CUSTOMER c ON o.CUSTOMER_ID = c.CUSTOMER_ID
WHERE c.LASTNAME = 'Dunn'
GROUP BY i.INVOICE_ID 
 



