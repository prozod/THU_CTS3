package thisandthat;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.EntityTransaction;

import java.util.List;

public class CustomerService {

    private EntityManagerFactory emf;
    private EntityManager entityManager;

    public CustomerService() {
        // factor this out somehow, the entitymanager as a separate unit so that every service connects faster
        emf = Persistence.createEntityManagerFactory("thisandthatJPA");
        entityManager = emf.createEntityManager();
    }

    public void createCustomer(String customerFirstname, String customerSurname, String salutation) {
        EntityTransaction transaction = entityManager.getTransaction();
        try {
            transaction.begin();
            Customer customer = new Customer();
            customer.setCustomerFirstname(customerFirstname);
            customer.setCustomerSurname(customerSurname);
            customer.setSalutation(salutation);
            entityManager.persist(customer);
            transaction.commit();
        } catch (Exception e) {
            transaction.rollback();
            e.printStackTrace();
        }
    }

    public Customer findCustomerById(Long id) {
        return entityManager.find(Customer.class, id);
    }

    public Customer updateCustomer(Long id, String newCustomerFirstname, String newCustomerSurname, String salutation) {
        EntityTransaction transaction = entityManager.getTransaction();
        try {
            transaction.begin();
            Customer customer = entityManager.find(Customer.class, id);
            if (customer != null) {
                customer.setCustomerSurname(newCustomerSurname);
                customer.setCustomerFirstname(newCustomerSurname);
                customer.setSalutation(salutation);
                entityManager.merge(customer);
            }
            transaction.commit();
            return customer;
        } catch (Exception e) {
            transaction.rollback();
            e.printStackTrace();
            return null;
        }
    }

    public void deleteCustomer(Long id) {
        EntityTransaction transaction = entityManager.getTransaction();
        try {
            transaction.begin();
            Customer customer = entityManager.find(Customer.class, id);
            if (customer != null) {
                entityManager.remove(customer);
            }
            transaction.commit();
        } catch (Exception e) {
            transaction.rollback();
            e.printStackTrace();
        }
    }

    public List<Customer> getAllCustomers() {
        return entityManager.createQuery("SELECT c FROM Customer c", Customer.class).getResultList();
    }

    // Close EntityManager
    public void close() {
        entityManager.close();
        emf.close();
    }
}
