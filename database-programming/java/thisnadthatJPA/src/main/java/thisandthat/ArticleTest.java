package thisandthat;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

public class ArticleTest {
    private EntityManagerFactory emf;
    private EntityManager em;
    public Long newlyCreatedArticleId;

    public ArticleTest() {
        emf = Persistence.createEntityManagerFactory("thisandthatJPA");
        em = emf.createEntityManager();
    }

    public createAutomaticTest() {
        ArticleService articleService = new ArticleService();

        Article newArt = articleService.createArticle("Keyboard", 20.99, "EUR");
        newlyCreatedArticleId = newArt.getArticleId();


        articleService.close();
    }


}
