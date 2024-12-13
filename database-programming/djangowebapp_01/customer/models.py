from django.db import models


class Address(models.Model):
    street = models.CharField(max_length=200)
    country = models.CharField(max_length=2)
    postal_code = models.CharField(max_length=10)
    city = models.CharField(max_length=255)
    deleted = models.IntegerField(default=0)

    def __str__(self):
        return self.street + ", " + self.postal_code + " " + self.city

    def local_address(self):
        return self.country == "DE"


class Customer(models.Model):
    firstname = models.CharField(max_length=200)
    surname = models.CharField(max_length=200)
    salutation = models.CharField(max_length=50)
    type = models.CharField('customer type', max_length=50)
    address = models.ForeignKey(
        Address, on_delete=models.DO_NOTHING, null=True)
    created = models.DateTimeField(auto_now=True)  # Default now
    deleted = models.IntegerField(default=0)

    def __str__(self):
        return self.surname + ", " + self.firstname
