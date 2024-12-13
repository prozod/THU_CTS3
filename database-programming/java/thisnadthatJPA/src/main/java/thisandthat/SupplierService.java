package thisandthat;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

import java.util.List;

public class SupplierService {
    private EntityManagerFactory emf;
    private EntityManager em;

    public SupplierService() {
        emf = Persistence.createEntityManagerFactory("thisandthatJPA");
        em = emf.createEntityManager();
    }

    public List<Supplier> getSuppliers() {
        return em.createQuery("SELECT s FROM Supplier s", Supplier.class).getResultList();
    }

    public void close() {
        em.close();
        emf.close();
    }
}
