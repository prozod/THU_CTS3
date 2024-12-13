package thisandthatDAO;

import java.sql.SQLException;
import java.util.List;

public class Article {
    private int article_Id;
    private String articleName;
    private float price;
    private String currency;
    private boolean deleted;
    private List<ArticleGroup> articleGroups;

    public void setArticle_Id(int id) {
        this.article_Id = id;
    }

    public int getArticle_Id() {
        return article_Id;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public float getPrice() {
        return price;
    }

    public void setCurrency(String cur) {
        this.currency = cur;
    }

    public String getCurrency() {
        return currency;
    }

    public void setDeleted(boolean deleted) {
        this.deleted = deleted;
    }

    public boolean isDeleted() {
        return deleted;
    }

    public void setArticleName(String name) {
        this.articleName = name;
    }

    public String getArticleName() {
        return articleName;
    }

    public void setArticleGroups(List groups) {
        this.articleGroups = groups;
    }

    public List<ArticleGroup> getArticleGroups(int article_Id) {
        return articleGroups;
    }

}
