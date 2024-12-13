package thisandthat;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

import java.util.List;

public class ArticleGroupService {
    private EntityManagerFactory emf;
    private EntityManager em;

    public ArticleGroupService() {
        emf = Persistence.createEntityManagerFactory("thisandthatJPA");
        em = emf.createEntityManager();
    }

    public List<ArticleGroup> getArticleGroups() {
        return em.createQuery("SELECT ag FROM ArticleGroup ag", ArticleGroup.class).getResultList();
    }

    public void close() {
        em.close();
        emf.close();
    }

}
