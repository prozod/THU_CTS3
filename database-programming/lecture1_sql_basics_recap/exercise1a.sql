INSERT INTO ARTICLE_NEW(ARTICLE_ID, ARTICLE, PRICE, CURRENCY, DELETED)
SELECT ARTICLE_ID, ARTICLE, PRICE, CURRENCY, DELETED 
FROM ARTICLE

DELETE FROM ARTICLE_NEW WHERE ARTICLE_ID='1'

DROP TABLE ARTICLE_NEW;