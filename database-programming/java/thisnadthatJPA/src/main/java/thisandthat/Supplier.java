package thisandthat;

import jakarta.persistence.*;

@Entity
@Table(name = "supplier")
public class Supplier {
    @Id
    @Column(name = "SUPPLIER_ID", nullable = false)
    @GeneratedValue(strategy = GenerationType.TABLE)
    private Long supplierId;

    @Column(name = "SUPPLIER", length = 255, nullable = false)
    private String supplier;

    @Column(name = "ADDRESS_ID", nullable = false)
    private Long addressId;

    @Column(name = "DELETED", nullable = false)
    private short deleted;

    @Override
    public String toString() {
        return "Supplier{" +
                "id=" + supplierId +
                ", supplier='" + supplier + '\'' +
                ", addressId='" + addressId + '\'' +
                '}';
    }
}
