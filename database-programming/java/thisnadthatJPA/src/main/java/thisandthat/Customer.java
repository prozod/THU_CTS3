package thisandthat;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Column;
import jakarta.persistence.Table;

@Entity
@Table(name = "Customer")
public class Customer {

    @Id
    @Column(name = "CUSTOMER_ID")
    @GeneratedValue(strategy = GenerationType.TABLE)
    private Long customerId;

    @Column(name = "LASTNAME")
    private String customerLastname;
    @Column(name = "FIRSTNAME")
    private String customerFirstname;

    @Column(name = "INVOICE_ADDRESS_ID")
    private int invoice_address_id;

    @Column(name = "SALUTATION")
    private String salutation;

    public Long getId() {
        return customerId;
    }

    public void setId(Long id) {
        this.customerId = id;
    }

    public String getCustomerName() {
        return customerFirstname + " " + customerLastname;
    }

    public void setCustomerFirstname(String customerFirstName) {
        this.customerFirstname = customerFirstName;
    }

    public void setCustomerSurname(String customerLastname) {
        this.customerLastname = customerLastname;
    }

    public String getSalutation() {
        return salutation;
    }

    public void setSalutation(String salutation) {
        this.salutation = salutation;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "id=" + customerId +
                ", customerName='" + customerLastname + " " + customerFirstname + '\'' +
                ", invoice_address_id='" + invoice_address_id + '\'' +
                '}';
    }
}
