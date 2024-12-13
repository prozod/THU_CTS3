package thisandthat;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.EntityTransaction;
import jakarta.persistence.Persistence;

import java.sql.SQLException;
import java.util.List;

public class ArticleService {
    private EntityManagerFactory emf;
    private EntityManager em;

    public ArticleService() {
        emf = Persistence.createEntityManagerFactory("thisandthatJPA");
        em = emf.createEntityManager();
    }

    public List<Article> getArticles() {
        return em.createQuery("SELECT a FROM Article a", Article.class).getResultList();
    }

    public Article createArticle(String article, Double price, String currency) {
        EntityTransaction transaction = em.getTransaction();
        try {
            Article newArticle = new Article();
            newArticle.setArticle(article);
            newArticle.setPrice(price);
            newArticle.setCurrency(currency);
            em.persist(newArticle);
            transaction.commit();
        } catch (Exception e) {
            transaction.rollback();
            e.printStackTrace();
        }
    }

    public Article findArticleById(Long id) {
        return em.find(Article.class, id);
    }

    public void deleteArticle(Long id) {
        EntityTransaction transaction = em.getTransaction();
        try {
            transaction.begin();
            Article article = em.find(Article.class, id);
            if (article != null) {
                em.remove(article);
            }
            transaction.commit();
        } catch (Exception e) {
            transaction.rollback();
            e.printStackTrace();
        }
    }

    public void close() {
        em.close();
        emf.close();
    }
}
