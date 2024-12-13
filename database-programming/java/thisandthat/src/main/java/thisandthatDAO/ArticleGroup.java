package thisandthatDAO;

import java.util.List;

public class ArticleGroup {
    private int articleGroupId;
    private String articleGroupName;
    private boolean deleted;

    public List<Article> getArticles() {
        return articles;
    }

    public void setArticles(List<Article> articles) {
        this.articles = articles;
    }

    private List<Article> articles;

    public int getArticleGroupId() {
        return articleGroupId;
    }

    public void setArticleGroupId(int articleGroupId) {
        this.articleGroupId = articleGroupId;
    }

    public String getArticleGroupName() {
        return articleGroupName;
    }

    public void setArticleGroupName(String articleGroupName) {
        this.articleGroupName = articleGroupName;
    }

    public boolean isDeleted() {
        return deleted;
    }

    public void setDeleted(boolean deleted) {
        this.deleted = deleted;
    }

}
