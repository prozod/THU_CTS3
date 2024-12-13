from article.models import Article, ArticleGroup
import os
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'djangowebapp_01.settings')
django.setup()


def run_queries():
    gifts_group, created = ArticleGroup.objects.get_or_create(
        articlegroup="Gifts")
    print(str(gifts_group))

    def get_or_create_article(article_name, price, currency):
        article, created = Article.objects.get_or_create(
            article=article_name,
            defaults={'price': price, 'currency': currency}
        )
        return article

    article1 = get_or_create_article("RC Car", 49.95, "EUR")
    article2 = get_or_create_article("Puppet", 10.00, "EUR")
    article3 = get_or_create_article("Electric Guitar", 249.95, "EUR")

    gifts_group.articles.add(article1, article2, article3)
    print(str(gifts_group))

    articles = Article.objects.all()
    for article in articles:
        print(article)


if __name__ == "__main__":
    run_queries()
