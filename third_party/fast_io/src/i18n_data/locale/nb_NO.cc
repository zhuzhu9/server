﻿#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("nb_NO"),.encoding=tsc(FAST_IO_LOCALE_ENCODING),.title=tsc("Norwegian (Bokmål) locale for Norway"),.source=tsc("Norsk Standardiseringsforbund\t\t;\t\tfast_io"),.address=tsc("University Library, Drammensveien 41, N-9242 Oslo, Norge\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc("fast_io"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Norwegian Bokmål"),.territory=tsc("Norway"),.revision=tsc("1.0"),.date=tsc("2000-06-29")},.monetary={.int_curr_symbol=tsc("NOK "),.currency_symbol=tsc("kr"),.mon_decimal_point=tsc(","),.mon_thousands_sep=tsc(" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc(" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("sø."),tsc("ma."),tsc("ti."),tsc("on."),tsc("to."),tsc("fr."),tsc("lø.")},.day={tsc("søndag"),tsc("mandag"),tsc("tirsdag"),tsc("onsdag"),tsc("torsdag"),tsc("fredag"),tsc("lørdag")},.abmon={tsc("jan."),tsc("feb."),tsc("mars"),tsc("april"),tsc("mai"),tsc("juni"),tsc("juli"),tsc("aug."),tsc("sep."),tsc("okt."),tsc("nov."),tsc("des.")},.mon={tsc("januar"),tsc("februar"),tsc("mars"),tsc("april"),tsc("mai"),tsc("juni"),tsc("juli"),tsc("august"),tsc("september"),tsc("oktober"),tsc("november"),tsc("desember")},.d_t_fmt=tsc("%a %d. %b %Y kl. %H.%M %z"),.d_fmt=tsc("%d. %b %Y"),.t_fmt=tsc("kl. %H.%M %z"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a %d. %b %H:%M:%S %z %Y"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1JjYy]"),.noexpr=tsc("^[-0Nn]"),.yesstr=tsc("ja"),.nostr=tsc("nei")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %l"),.tel_dom_fmt=tsc("%l"),.int_select=tsc("00"),.int_prefix=tsc("47")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Norge"),.country_ab2=tsc("NO"),.country_ab3=tsc("NOR"),.country_num=578,.country_car=tsc("N"),.lang_name=tsc("norsk bokmål"),.lang_ab=tsc("nb"),.lang_term=tsc("nob"),.lang_lib=tsc("nob")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"nb_NO"),.encoding=tsc(FAST_IO_LOCALE_LENCODING),.title=tsc(L"Norwegian (Bokmål) locale for Norway"),.source=tsc(L"Norsk Standardiseringsforbund\t\t;\t\tfast_io"),.address=tsc(L"University Library, Drammensveien 41, N-9242 Oslo, Norge\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Norwegian Bokmål"),.territory=tsc(L"Norway"),.revision=tsc(L"1.0"),.date=tsc(L"2000-06-29")},.monetary={.int_curr_symbol=tsc(L"NOK "),.currency_symbol=tsc(L"kr"),.mon_decimal_point=tsc(L","),.mon_thousands_sep=tsc(L" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"sø."),tsc(L"ma."),tsc(L"ti."),tsc(L"on."),tsc(L"to."),tsc(L"fr."),tsc(L"lø.")},.day={tsc(L"søndag"),tsc(L"mandag"),tsc(L"tirsdag"),tsc(L"onsdag"),tsc(L"torsdag"),tsc(L"fredag"),tsc(L"lørdag")},.abmon={tsc(L"jan."),tsc(L"feb."),tsc(L"mars"),tsc(L"april"),tsc(L"mai"),tsc(L"juni"),tsc(L"juli"),tsc(L"aug."),tsc(L"sep."),tsc(L"okt."),tsc(L"nov."),tsc(L"des.")},.mon={tsc(L"januar"),tsc(L"februar"),tsc(L"mars"),tsc(L"april"),tsc(L"mai"),tsc(L"juni"),tsc(L"juli"),tsc(L"august"),tsc(L"september"),tsc(L"oktober"),tsc(L"november"),tsc(L"desember")},.d_t_fmt=tsc(L"%a %d. %b %Y kl. %H.%M %z"),.d_fmt=tsc(L"%d. %b %Y"),.t_fmt=tsc(L"kl. %H.%M %z"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a %d. %b %H:%M:%S %z %Y"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1JjYy]"),.noexpr=tsc(L"^[-0Nn]"),.yesstr=tsc(L"ja"),.nostr=tsc(L"nei")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %l"),.tel_dom_fmt=tsc(L"%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"47")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Norge"),.country_ab2=tsc(L"NO"),.country_ab3=tsc(L"NOR"),.country_num=578,.country_car=tsc(L"N"),.lang_name=tsc(L"norsk bokmål"),.lang_ab=tsc(L"nb"),.lang_term=tsc(L"nob"),.lang_lib=tsc(L"nob")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"nb_NO"),.encoding=tsc(FAST_IO_LOCALE_u8ENCODING),.title=tsc(u8"Norwegian (Bokmål) locale for Norway"),.source=tsc(u8"Norsk Standardiseringsforbund\t\t;\t\tfast_io"),.address=tsc(u8"University Library, Drammensveien 41, N-9242 Oslo, Norge\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Norwegian Bokmål"),.territory=tsc(u8"Norway"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000-06-29")},.monetary={.int_curr_symbol=tsc(u8"NOK "),.currency_symbol=tsc(u8"kr"),.mon_decimal_point=tsc(u8","),.mon_thousands_sep=tsc(u8" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"sø."),tsc(u8"ma."),tsc(u8"ti."),tsc(u8"on."),tsc(u8"to."),tsc(u8"fr."),tsc(u8"lø.")},.day={tsc(u8"søndag"),tsc(u8"mandag"),tsc(u8"tirsdag"),tsc(u8"onsdag"),tsc(u8"torsdag"),tsc(u8"fredag"),tsc(u8"lørdag")},.abmon={tsc(u8"jan."),tsc(u8"feb."),tsc(u8"mars"),tsc(u8"april"),tsc(u8"mai"),tsc(u8"juni"),tsc(u8"juli"),tsc(u8"aug."),tsc(u8"sep."),tsc(u8"okt."),tsc(u8"nov."),tsc(u8"des.")},.mon={tsc(u8"januar"),tsc(u8"februar"),tsc(u8"mars"),tsc(u8"april"),tsc(u8"mai"),tsc(u8"juni"),tsc(u8"juli"),tsc(u8"august"),tsc(u8"september"),tsc(u8"oktober"),tsc(u8"november"),tsc(u8"desember")},.d_t_fmt=tsc(u8"%a %d. %b %Y kl. %H.%M %z"),.d_fmt=tsc(u8"%d. %b %Y"),.t_fmt=tsc(u8"kl. %H.%M %z"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a %d. %b %H:%M:%S %z %Y"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1JjYy]"),.noexpr=tsc(u8"^[-0Nn]"),.yesstr=tsc(u8"ja"),.nostr=tsc(u8"nei")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %l"),.tel_dom_fmt=tsc(u8"%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"47")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Norge"),.country_ab2=tsc(u8"NO"),.country_ab3=tsc(u8"NOR"),.country_num=578,.country_car=tsc(u8"N"),.lang_name=tsc(u8"norsk bokmål"),.lang_ab=tsc(u8"nb"),.lang_term=tsc(u8"nob"),.lang_lib=tsc(u8"nob")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"nb_NO"),.encoding=tsc(FAST_IO_LOCALE_uENCODING),.title=tsc(u"Norwegian (Bokmål) locale for Norway"),.source=tsc(u"Norsk Standardiseringsforbund\t\t;\t\tfast_io"),.address=tsc(u"University Library, Drammensveien 41, N-9242 Oslo, Norge\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Norwegian Bokmål"),.territory=tsc(u"Norway"),.revision=tsc(u"1.0"),.date=tsc(u"2000-06-29")},.monetary={.int_curr_symbol=tsc(u"NOK "),.currency_symbol=tsc(u"kr"),.mon_decimal_point=tsc(u","),.mon_thousands_sep=tsc(u" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"sø."),tsc(u"ma."),tsc(u"ti."),tsc(u"on."),tsc(u"to."),tsc(u"fr."),tsc(u"lø.")},.day={tsc(u"søndag"),tsc(u"mandag"),tsc(u"tirsdag"),tsc(u"onsdag"),tsc(u"torsdag"),tsc(u"fredag"),tsc(u"lørdag")},.abmon={tsc(u"jan."),tsc(u"feb."),tsc(u"mars"),tsc(u"april"),tsc(u"mai"),tsc(u"juni"),tsc(u"juli"),tsc(u"aug."),tsc(u"sep."),tsc(u"okt."),tsc(u"nov."),tsc(u"des.")},.mon={tsc(u"januar"),tsc(u"februar"),tsc(u"mars"),tsc(u"april"),tsc(u"mai"),tsc(u"juni"),tsc(u"juli"),tsc(u"august"),tsc(u"september"),tsc(u"oktober"),tsc(u"november"),tsc(u"desember")},.d_t_fmt=tsc(u"%a %d. %b %Y kl. %H.%M %z"),.d_fmt=tsc(u"%d. %b %Y"),.t_fmt=tsc(u"kl. %H.%M %z"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a %d. %b %H:%M:%S %z %Y"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1JjYy]"),.noexpr=tsc(u"^[-0Nn]"),.yesstr=tsc(u"ja"),.nostr=tsc(u"nei")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %l"),.tel_dom_fmt=tsc(u"%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"47")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Norge"),.country_ab2=tsc(u"NO"),.country_ab3=tsc(u"NOR"),.country_num=578,.country_car=tsc(u"N"),.lang_name=tsc(u"norsk bokmål"),.lang_ab=tsc(u"nb"),.lang_term=tsc(u"nob"),.lang_lib=tsc(u"nob")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"nb_NO"),.encoding=tsc(FAST_IO_LOCALE_UENCODING),.title=tsc(U"Norwegian (Bokmål) locale for Norway"),.source=tsc(U"Norsk Standardiseringsforbund\t\t;\t\tfast_io"),.address=tsc(U"University Library, Drammensveien 41, N-9242 Oslo, Norge\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Norwegian Bokmål"),.territory=tsc(U"Norway"),.revision=tsc(U"1.0"),.date=tsc(U"2000-06-29")},.monetary={.int_curr_symbol=tsc(U"NOK "),.currency_symbol=tsc(U"kr"),.mon_decimal_point=tsc(U","),.mon_thousands_sep=tsc(U" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=4,.n_sign_posn=4},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"sø."),tsc(U"ma."),tsc(U"ti."),tsc(U"on."),tsc(U"to."),tsc(U"fr."),tsc(U"lø.")},.day={tsc(U"søndag"),tsc(U"mandag"),tsc(U"tirsdag"),tsc(U"onsdag"),tsc(U"torsdag"),tsc(U"fredag"),tsc(U"lørdag")},.abmon={tsc(U"jan."),tsc(U"feb."),tsc(U"mars"),tsc(U"april"),tsc(U"mai"),tsc(U"juni"),tsc(U"juli"),tsc(U"aug."),tsc(U"sep."),tsc(U"okt."),tsc(U"nov."),tsc(U"des.")},.mon={tsc(U"januar"),tsc(U"februar"),tsc(U"mars"),tsc(U"april"),tsc(U"mai"),tsc(U"juni"),tsc(U"juli"),tsc(U"august"),tsc(U"september"),tsc(U"oktober"),tsc(U"november"),tsc(U"desember")},.d_t_fmt=tsc(U"%a %d. %b %Y kl. %H.%M %z"),.d_fmt=tsc(U"%d. %b %Y"),.t_fmt=tsc(U"kl. %H.%M %z"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a %d. %b %H:%M:%S %z %Y"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1JjYy]"),.noexpr=tsc(U"^[-0Nn]"),.yesstr=tsc(U"ja"),.nostr=tsc(U"nei")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %l"),.tel_dom_fmt=tsc(U"%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"47")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Norge"),.country_ab2=tsc(U"NO"),.country_ab3=tsc(U"NOR"),.country_num=578,.country_car=tsc(U"N"),.lang_name=tsc(U"norsk bokmål"),.lang_ab=tsc(U"nb"),.lang_term=tsc(U"nob"),.lang_lib=tsc(U"nob")},.measurement={.measurement=1}};


}
}

#include"../main.h"