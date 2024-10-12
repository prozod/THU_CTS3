CALL delete_order_pos(1, 7856);

/* 
- deci fiecare INVOICE are un ORDER_ID atasat (numarul comenzii)
-- acel ORDER_ID contine (sau nu) niste produse (pe care le-a comandat clientul)
--- produsele fiecarui ORDER sunt listate in ORDER_POSITION
---- atunci cand stergi un row ORDER_POSITION, acela exista si in INVOICE_POSITION (cu acelasi ORDER_ID, acelasi POSITION_NR)
----- deci trebuie sa stergi row-ul cu ID respectiv si din ORDER_POSITION, dar si din INVOICE_POSITION (sa keep it consistent)
------ daca row-ul sters are POSITION_NR = 2, atunci trebuie sa "rearanjam" randurile astfel incat dupa 1 sa urmeze 2 (articolul de pe pozitia 3 va avea pos 2)

------- PASUL 1: STERGEM ORDER_POSITION (ord_id si art_id) SI INVOICE_POSITION-ul (art_id, invoice_id)
-------- PASUL 2: INCA AVEM COMANDA (ORDER_ID), asa ca mergem in tabelele INVOICE_POSITION si ORDER_POSITION si facem un fel de magie
					iteratie (cumva - google forloop in SQL idk), peste toate articolele ramase in ORDER_ID respectiv si updatam POSITION_NR de la 1 la N
--------- PASUL 3: GATA? CRED? update later daca mai tre' ceva
*/

SELECT ip.INVOICE_ID, ip.ARTICLE_ID, ip.POSITION_NR, op.ORDER_ID, op.ARTICLE_ID, op.POSITION_NR 
FROM INVOICE i 
JOIN INVOICE_POSITION ip ON i.INVOICE_ID = ip.INVOICE_ID 
JOIN `ORDER` o ON i.ORDER_ID = o.ORDER_ID 
JOIN ORDER_POSITION op ON op.ORDER_ID = o.ORDER_ID 
WHERE o.ORDER_ID = 1;

SELECT * FROM ORDER_POSITION;
SELECT * FROM INVOICE_POSITION;