#include "push_swap.h"


/*
şimdi napacaz düşünelim önce bir kaç durum var onları ele alacaz:
sıralı gelmiş olabilir bu 1
şu 3-5 küçük sayılı durumda radix falan diğerleri de verimsiz çalışıyor o yüzden
özel case eklicem i dont care yani
şimdilik böyle
*/


int is_sorted(t_stack *a)
{
    int i;
    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void to_top(t_environment *env, int en_uste_cikarilacak_hedef_deger)
{
	int hedef_degerin_stackteki_konumu;
	int stack_a_toplam_eleman_sayisi;
	int asagidan_kac_adimda_ulasilacagi;

	hedef_degerin_stackteki_konumu = 0;
	
	while (env->a->data[hedef_degerin_stackteki_konumu] != en_uste_cikarilacak_hedef_deger)
	{
		hedef_degerin_stackteki_konumu++;
	}
		
	stack_a_toplam_eleman_sayisi = env->a->size;
	
	if (hedef_degerin_stackteki_konumu <= (stack_a_toplam_eleman_sayisi / 2))
	{
		while (hedef_degerin_stackteki_konumu-- > 0)
			ra(env);
	}
	else
	{
		asagidan_kac_adimda_ulasilacagi = stack_a_toplam_eleman_sayisi - hedef_degerin_stackteki_konumu - 1;
		
		while (asagidan_kac_adimda_ulasilacagi-- > 0)
			rra(env);
	}
}

void sort_three(t_environment *env)
{
}


void small_sort(t_environment *env)
{
	int b_stackine_gonderilecek_eleman_sayisi;
	int su_an_aranan_kucuk_deger;
	if (env->a->size == 2)
	{
		if (env->a->data[0] > env->a->data[1])
			sa(env);
		return ;
	}
    /*
    mantık şöyle a'da 3 tane bırakıcaz o yüzden çıkarma işlemi yapıcaz b'de kaç tane olacağını bulabilmek için
    */
	b_stackine_gonderilecek_eleman_sayisi = env->a->size - 3;
	su_an_aranan_kucuk_deger = 0;
	while (su_an_aranan_kucuk_deger < b_stackine_gonderilecek_eleman_sayisi)
	{
		to_top(env, su_an_aranan_kucuk_deger);
		pb(env);
		su_an_aranan_kucuk_deger++;
	}
	sort_three(env);
}

void radix_sort(t_environment *env)
{
    int i;
    int bit;

    if (is_sorted(env->a))
    {
        return ;
    }
    if (env->a->size <= 5)
    {
        return (small_sort(env));
    }

    


}