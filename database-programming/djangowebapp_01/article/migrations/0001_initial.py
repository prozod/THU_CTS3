# Generated by Django 5.1.3 on 2024-12-10 08:59

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = []

    operations = [
        migrations.CreateModel(
            name="ArticleGroup",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("articlegroup", models.CharField(max_length=255)),
                ("deleted", models.IntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name="Article",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("article", models.CharField(max_length=255)),
                ("price", models.DecimalField(decimal_places=2, max_digits=9)),
                ("currency", models.CharField(max_length=3)),
                ("deleted", models.IntegerField(default=0)),
                (
                    "groups",
                    models.ManyToManyField(
                        blank=True, related_name="articles", to="article.articlegroup"
                    ),
                ),
            ],
        ),
    ]
