﻿#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t monetary_mon_grouping_storage[]{3,2};

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.name=tsc("sd_IN@devanagari"),.encoding=tsc(FAST_IO_LOCALE_ENCODING),.title=tsc("Sindhi language locale for India"),.source=tsc("Red Hat, Pune\t\t;\t\tfast_io"),.address=tsc("Marisfot III, Marigold Premises, East-Wing, Kalyaninagar, Pune, India-411014\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc("fast_io"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Sindhi"),.territory=tsc("India"),.revision=tsc("1.0"),.date=tsc("2008-08-26")},.monetary={.int_curr_symbol=tsc("INR "),.currency_symbol=tsc("₹"),.mon_decimal_point=tsc("."),.mon_thousands_sep=tsc(","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc("."),.thousands_sep=tsc(","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("आर्तवारू"),tsc("सूमरू"),tsc("मंगलू"),tsc("ॿुधरू"),tsc("विस्पति"),tsc("जुमो"),tsc("छंछस")},.day={tsc("आर्तवारू"),tsc("सूमरू"),tsc("मंगलू"),tsc("ॿुधरू"),tsc("विस्पति"),tsc("जुमो"),tsc("छंछस")},.abmon={tsc("जनवरी"),tsc("फबरवरी"),tsc("मार्चि"),tsc("अप्रेल"),tsc("मे"),tsc("जूनि"),tsc("जूलाइ"),tsc("आगस्टु"),tsc("सेप्टेंबरू"),tsc("आक्टूबरू"),tsc("नवंबरू"),tsc("ॾिसंबरू")},.mon={tsc("जनवरी"),tsc("फबरवरी"),tsc("मार्चि"),tsc("अप्रेल"),tsc("मे"),tsc("जूनि"),tsc("जूलाइ"),tsc("आगस्टु"),tsc("सेप्टेंबरू"),tsc("आक्टूबरू"),tsc("नवंबरू"),tsc("ॾिसंबरू")},.d_t_fmt=tsc("%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc("%-d//%-m//%y"),.t_fmt=tsc("%I:%M:%S %p %Z"),.t_fmt_ampm=tsc("%I:%M:%S %p %Z"),.date_fmt=tsc("%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc("म.पू."),tsc("म.नं.")},.week={7,19971130,1}},.messages={.yesexpr=tsc("^[+1yY]"),.noexpr=tsc("^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c ;%a ;%l"),.int_select=tsc("00"),.int_prefix=tsc("91")},.name={.name_fmt=tsc("%p%t%f%t%g"),.name_gen=tsc(""),.name_miss=tsc("कुमारी."),.name_mr=tsc("श्री."),.name_mrs=tsc("श्रीमती."),.name_ms=tsc("कुमार.")},.address={.postal_fmt=tsc("%z%c%T%s%b%e%r"),.country_name=tsc("भारत"),.country_ab2=tsc("IN"),.country_ab3=tsc("IND"),.country_num=356,.country_car=tsc("IND"),.lang_name=tsc("सिन्धी"),.lang_ab=tsc("sd"),.lang_term=tsc("snd"),.lang_lib=tsc("snd")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.name=tsc(L"sd_IN@devanagari"),.encoding=tsc(FAST_IO_LOCALE_LENCODING),.title=tsc(L"Sindhi language locale for India"),.source=tsc(L"Red Hat, Pune\t\t;\t\tfast_io"),.address=tsc(L"Marisfot III, Marigold Premises, East-Wing, Kalyaninagar, Pune, India-411014\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Sindhi"),.territory=tsc(L"India"),.revision=tsc(L"1.0"),.date=tsc(L"2008-08-26")},.monetary={.int_curr_symbol=tsc(L"INR "),.currency_symbol=tsc(L"₹"),.mon_decimal_point=tsc(L"."),.mon_thousands_sep=tsc(L","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L"."),.thousands_sep=tsc(L","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"आर्तवारू"),tsc(L"सूमरू"),tsc(L"मंगलू"),tsc(L"ॿुधरू"),tsc(L"विस्पति"),tsc(L"जुमो"),tsc(L"छंछस")},.day={tsc(L"आर्तवारू"),tsc(L"सूमरू"),tsc(L"मंगलू"),tsc(L"ॿुधरू"),tsc(L"विस्पति"),tsc(L"जुमो"),tsc(L"छंछस")},.abmon={tsc(L"जनवरी"),tsc(L"फबरवरी"),tsc(L"मार्चि"),tsc(L"अप्रेल"),tsc(L"मे"),tsc(L"जूनि"),tsc(L"जूलाइ"),tsc(L"आगस्टु"),tsc(L"सेप्टेंबरू"),tsc(L"आक्टूबरू"),tsc(L"नवंबरू"),tsc(L"ॾिसंबरू")},.mon={tsc(L"जनवरी"),tsc(L"फबरवरी"),tsc(L"मार्चि"),tsc(L"अप्रेल"),tsc(L"मे"),tsc(L"जूनि"),tsc(L"जूलाइ"),tsc(L"आगस्टु"),tsc(L"सेप्टेंबरू"),tsc(L"आक्टूबरू"),tsc(L"नवंबरू"),tsc(L"ॾिसंबरू")},.d_t_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(L"%-d//%-m//%y"),.t_fmt=tsc(L"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(L"%I:%M:%S %p %Z"),.date_fmt=tsc(L"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(L"म.पू."),tsc(L"म.नं.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(L"^[+1yY]"),.noexpr=tsc(L"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c ;%a ;%l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"91")},.name={.name_fmt=tsc(L"%p%t%f%t%g"),.name_gen=tsc(L""),.name_miss=tsc(L"कुमारी."),.name_mr=tsc(L"श्री."),.name_mrs=tsc(L"श्रीमती."),.name_ms=tsc(L"कुमार.")},.address={.postal_fmt=tsc(L"%z%c%T%s%b%e%r"),.country_name=tsc(L"भारत"),.country_ab2=tsc(L"IN"),.country_ab3=tsc(L"IND"),.country_num=356,.country_car=tsc(L"IND"),.lang_name=tsc(L"सिन्धी"),.lang_ab=tsc(L"sd"),.lang_term=tsc(L"snd"),.lang_lib=tsc(L"snd")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.name=tsc(u8"sd_IN@devanagari"),.encoding=tsc(FAST_IO_LOCALE_u8ENCODING),.title=tsc(u8"Sindhi language locale for India"),.source=tsc(u8"Red Hat, Pune\t\t;\t\tfast_io"),.address=tsc(u8"Marisfot III, Marigold Premises, East-Wing, Kalyaninagar, Pune, India-411014\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Sindhi"),.territory=tsc(u8"India"),.revision=tsc(u8"1.0"),.date=tsc(u8"2008-08-26")},.monetary={.int_curr_symbol=tsc(u8"INR "),.currency_symbol=tsc(u8"₹"),.mon_decimal_point=tsc(u8"."),.mon_thousands_sep=tsc(u8","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8"."),.thousands_sep=tsc(u8","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"आर्तवारू"),tsc(u8"सूमरू"),tsc(u8"मंगलू"),tsc(u8"ॿुधरू"),tsc(u8"विस्पति"),tsc(u8"जुमो"),tsc(u8"छंछस")},.day={tsc(u8"आर्तवारू"),tsc(u8"सूमरू"),tsc(u8"मंगलू"),tsc(u8"ॿुधरू"),tsc(u8"विस्पति"),tsc(u8"जुमो"),tsc(u8"छंछस")},.abmon={tsc(u8"जनवरी"),tsc(u8"फबरवरी"),tsc(u8"मार्चि"),tsc(u8"अप्रेल"),tsc(u8"मे"),tsc(u8"जूनि"),tsc(u8"जूलाइ"),tsc(u8"आगस्टु"),tsc(u8"सेप्टेंबरू"),tsc(u8"आक्टूबरू"),tsc(u8"नवंबरू"),tsc(u8"ॾिसंबरू")},.mon={tsc(u8"जनवरी"),tsc(u8"फबरवरी"),tsc(u8"मार्चि"),tsc(u8"अप्रेल"),tsc(u8"मे"),tsc(u8"जूनि"),tsc(u8"जूलाइ"),tsc(u8"आगस्टु"),tsc(u8"सेप्टेंबरू"),tsc(u8"आक्टूबरू"),tsc(u8"नवंबरू"),tsc(u8"ॾिसंबरू")},.d_t_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u8"%-d//%-m//%y"),.t_fmt=tsc(u8"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u8"%I:%M:%S %p %Z"),.date_fmt=tsc(u8"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u8"म.पू."),tsc(u8"म.नं.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u8"^[+1yY]"),.noexpr=tsc(u8"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c ;%a ;%l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"91")},.name={.name_fmt=tsc(u8"%p%t%f%t%g"),.name_gen=tsc(u8""),.name_miss=tsc(u8"कुमारी."),.name_mr=tsc(u8"श्री."),.name_mrs=tsc(u8"श्रीमती."),.name_ms=tsc(u8"कुमार.")},.address={.postal_fmt=tsc(u8"%z%c%T%s%b%e%r"),.country_name=tsc(u8"भारत"),.country_ab2=tsc(u8"IN"),.country_ab3=tsc(u8"IND"),.country_num=356,.country_car=tsc(u8"IND"),.lang_name=tsc(u8"सिन्धी"),.lang_ab=tsc(u8"sd"),.lang_term=tsc(u8"snd"),.lang_lib=tsc(u8"snd")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.name=tsc(u"sd_IN@devanagari"),.encoding=tsc(FAST_IO_LOCALE_uENCODING),.title=tsc(u"Sindhi language locale for India"),.source=tsc(u"Red Hat, Pune\t\t;\t\tfast_io"),.address=tsc(u"Marisfot III, Marigold Premises, East-Wing, Kalyaninagar, Pune, India-411014\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Sindhi"),.territory=tsc(u"India"),.revision=tsc(u"1.0"),.date=tsc(u"2008-08-26")},.monetary={.int_curr_symbol=tsc(u"INR "),.currency_symbol=tsc(u"₹"),.mon_decimal_point=tsc(u"."),.mon_thousands_sep=tsc(u","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u"."),.thousands_sep=tsc(u","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"आर्तवारू"),tsc(u"सूमरू"),tsc(u"मंगलू"),tsc(u"ॿुधरू"),tsc(u"विस्पति"),tsc(u"जुमो"),tsc(u"छंछस")},.day={tsc(u"आर्तवारू"),tsc(u"सूमरू"),tsc(u"मंगलू"),tsc(u"ॿुधरू"),tsc(u"विस्पति"),tsc(u"जुमो"),tsc(u"छंछस")},.abmon={tsc(u"जनवरी"),tsc(u"फबरवरी"),tsc(u"मार्चि"),tsc(u"अप्रेल"),tsc(u"मे"),tsc(u"जूनि"),tsc(u"जूलाइ"),tsc(u"आगस्टु"),tsc(u"सेप्टेंबरू"),tsc(u"आक्टूबरू"),tsc(u"नवंबरू"),tsc(u"ॾिसंबरू")},.mon={tsc(u"जनवरी"),tsc(u"फबरवरी"),tsc(u"मार्चि"),tsc(u"अप्रेल"),tsc(u"मे"),tsc(u"जूनि"),tsc(u"जूलाइ"),tsc(u"आगस्टु"),tsc(u"सेप्टेंबरू"),tsc(u"आक्टूबरू"),tsc(u"नवंबरू"),tsc(u"ॾिसंबरू")},.d_t_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(u"%-d//%-m//%y"),.t_fmt=tsc(u"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(u"%I:%M:%S %p %Z"),.date_fmt=tsc(u"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(u"म.पू."),tsc(u"म.नं.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(u"^[+1yY]"),.noexpr=tsc(u"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c ;%a ;%l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"91")},.name={.name_fmt=tsc(u"%p%t%f%t%g"),.name_gen=tsc(u""),.name_miss=tsc(u"कुमारी."),.name_mr=tsc(u"श्री."),.name_mrs=tsc(u"श्रीमती."),.name_ms=tsc(u"कुमार.")},.address={.postal_fmt=tsc(u"%z%c%T%s%b%e%r"),.country_name=tsc(u"भारत"),.country_ab2=tsc(u"IN"),.country_ab3=tsc(u"IND"),.country_num=356,.country_car=tsc(u"IND"),.lang_name=tsc(u"सिन्धी"),.lang_ab=tsc(u"sd"),.lang_term=tsc(u"snd"),.lang_lib=tsc(u"snd")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.name=tsc(U"sd_IN@devanagari"),.encoding=tsc(FAST_IO_LOCALE_UENCODING),.title=tsc(U"Sindhi language locale for India"),.source=tsc(U"Red Hat, Pune\t\t;\t\tfast_io"),.address=tsc(U"Marisfot III, Marigold Premises, East-Wing, Kalyaninagar, Pune, India-411014\t\t;\t\thttps://gitee.com/qabeowjbtkwb/fast_io\t\t;\t\thttps://github.com/cppfastio/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Sindhi"),.territory=tsc(U"India"),.revision=tsc(U"1.0"),.date=tsc(U"2008-08-26")},.monetary={.int_curr_symbol=tsc(U"INR "),.currency_symbol=tsc(U"₹"),.mon_decimal_point=tsc(U"."),.mon_thousands_sep=tsc(U","),.mon_grouping={monetary_mon_grouping_storage,2},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=1,.p_sep_by_space=0,.n_cs_precedes=1,.n_sep_by_space=0,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U"."),.thousands_sep=tsc(U","),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"आर्तवारू"),tsc(U"सूमरू"),tsc(U"मंगलू"),tsc(U"ॿुधरू"),tsc(U"विस्पति"),tsc(U"जुमो"),tsc(U"छंछस")},.day={tsc(U"आर्तवारू"),tsc(U"सूमरू"),tsc(U"मंगलू"),tsc(U"ॿुधरू"),tsc(U"विस्पति"),tsc(U"जुमो"),tsc(U"छंछस")},.abmon={tsc(U"जनवरी"),tsc(U"फबरवरी"),tsc(U"मार्चि"),tsc(U"अप्रेल"),tsc(U"मे"),tsc(U"जूनि"),tsc(U"जूलाइ"),tsc(U"आगस्टु"),tsc(U"सेप्टेंबरू"),tsc(U"आक्टूबरू"),tsc(U"नवंबरू"),tsc(U"ॾिसंबरू")},.mon={tsc(U"जनवरी"),tsc(U"फबरवरी"),tsc(U"मार्चि"),tsc(U"अप्रेल"),tsc(U"मे"),tsc(U"जूनि"),tsc(U"जूलाइ"),tsc(U"आगस्टु"),tsc(U"सेप्टेंबरू"),tsc(U"आक्टूबरू"),tsc(U"नवंबरू"),tsc(U"ॾिसंबरू")},.d_t_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p"),.d_fmt=tsc(U"%-d//%-m//%y"),.t_fmt=tsc(U"%I:%M:%S %p %Z"),.t_fmt_ampm=tsc(U"%I:%M:%S %p %Z"),.date_fmt=tsc(U"%A %d %b %Y %I:%M:%S %p %Z"),.am_pm={tsc(U"म.पू."),tsc(U"म.नं.")},.week={7,19971130,1}},.messages={.yesexpr=tsc(U"^[+1yY]"),.noexpr=tsc(U"^[-0nN]")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c ;%a ;%l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"91")},.name={.name_fmt=tsc(U"%p%t%f%t%g"),.name_gen=tsc(U""),.name_miss=tsc(U"कुमारी."),.name_mr=tsc(U"श्री."),.name_mrs=tsc(U"श्रीमती."),.name_ms=tsc(U"कुमार.")},.address={.postal_fmt=tsc(U"%z%c%T%s%b%e%r"),.country_name=tsc(U"भारत"),.country_ab2=tsc(U"IN"),.country_ab3=tsc(U"IND"),.country_num=356,.country_car=tsc(U"IND"),.lang_name=tsc(U"सिन्धी"),.lang_ab=tsc(U"sd"),.lang_term=tsc(U"snd"),.lang_lib=tsc(U"snd")},.measurement={.measurement=1}};


}
}

#include"../main.h"