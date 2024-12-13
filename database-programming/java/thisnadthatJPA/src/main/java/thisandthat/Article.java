package thisandthat;

import jakarta.persistence.*;

@Entity
@Table(name = "article")
public class Article {
    public Long getArticleId() {
        return articleId;
    }

    public void setArticleId(Long articleId) {
        this.articleId = articleId;
    }

    @Id
    @Column(name = "ARTICLE_ID", nullable = false)
    @GeneratedValue(strategy = GenerationType.TABLE)
    private Long articleId;

    public String getArticle() {
        return article;
    }

    public void setArticle(String article) {
        this.article = article;
    }

    @Column(name = "ARTICLE", nullable = false)
    private String article;

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Column(name = "PRICE", nullable = false)
    private double price;

    public String getCurrency() {
        return currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }

    @Column(name = "CURRENCY", nullable = true)
    private String currency;

    @Column(name = "DELETED", nullable = false)
    private short deleted;

    @Override
    public String toString() {
        return "Article{" +
                "id=" + articleId +
                ", article='" + article + '\'' +
                ", price='" + price + currency + '\'' +
                '}';
    }
}
