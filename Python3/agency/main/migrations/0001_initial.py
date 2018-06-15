# Generated by Django 2.0.6 on 2018-06-14 13:06

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='orderInfo',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('customerName', models.CharField(max_length=100, verbose_name='收货人姓名')),
                ('customerPhone', models.CharField(max_length=50, verbose_name='收货人电话')),
                ('customerAddress', models.CharField(max_length=500, verbose_name='收货人地址')),
                ('orderName', models.CharField(max_length=120, verbose_name='代理人姓名')),
            ],
            options={
                'verbose_name': '订单信息',
                'verbose_name_plural': '订单信息',
            },
        ),
    ]
