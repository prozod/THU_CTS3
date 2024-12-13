package thisandthat;

import jakarta.persistence.*;

@Entity
@Table(name = "articlegroup")
public class ArticleGroup {
    @Id
    @Column(name = "ARTICLEGROUP_ID")
    @GeneratedValue(strategy = GenerationType.TABLE)
    public Long articleGroupId;

    @Column(name = "ARTICLEGROUP", nullable = false, length = 255)
    public String articleGroup;

    @Column(name = "DELETED")
    private short deleted;

    @Override
    public String toString() {
        return "ArticleGroup{" +
                "id=" + articleGroupId +
                ", articleGroup='" + articleGroup + '\'' +
                ", deleted='" + deleted + '\'' +
                '}';
    }
}
