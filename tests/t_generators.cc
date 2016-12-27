#include "gtest/gtest.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <chaos.h>

////////////////////////////////////////////////////////////////////////////////

#define T_PRNG(x, cerf__0, cerf__1)                                            \
	TEST(GENERATORS, T__##x##__SignatureDefault) {                               \
		x prng_##x;                                                                \
                                                                               \
		std::ostringstream sign;                                                   \
		sign << std::hex << std::uppercase << std::setfill('0');                   \
		std::vector<x::size_next> v(128, 0);                                       \
                                                                               \
		std::generate(v.begin(), v.end(),                                          \
		              [&prng_##x] { return prng_##x.next(); });                    \
                                                                               \
		for (int block : v)                                                        \
			sign << std::setw(2) << block;                                           \
                                                                               \
		EXPECT_EQ(cerf__0, sign.str());                                            \
	}                                                                            \
                                                                               \
	TEST(GENERATORS, T__##x##__SignatureAdvanced) {                              \
		x prng_##x;                                                                \
                                                                               \
		std::ostringstream sign;                                                   \
		sign << std::hex << std::uppercase << std::setfill('0');                   \
		std::vector<x::size_next> v(128, 0);                                       \
                                                                               \
		prng_##x.seed(0xAA);                                                       \
                                                                               \
		std::generate(v.begin(), v.end(),                                          \
		              [&prng_##x] { return prng_##x.next(); });                    \
                                                                               \
		for (int block : v)                                                        \
			sign << std::setw(2) << block;                                           \
                                                                               \
		EXPECT_EQ(cerf__1, sign.str());                                            \
                                                                               \
		sign.str("");                                                              \
		sign.clear();                                                              \
                                                                               \
		prng_##x.seed(0xAA);                                                       \
                                                                               \
		std::generate(v.begin(), v.end(),                                          \
		              [&prng_##x] { return prng_##x.next(); });                    \
                                                                               \
		for (int block : v)                                                        \
			sign << std::setw(2) << block;                                           \
                                                                               \
		EXPECT_EQ(cerf__1, sign.str());                                            \
	}

/// abyssinian /////////////////////////////////////////////////////////////////

std::string abyssinian__cerf__0 =
    "6D19B78A39B479A09DC1634AD1466210AA92D8E532671BA1E02151DAD8D8A3DAE09B6716"
    "682684B6F22AE7A89CE81B615FA6EBAA56EC4C7D55D025D612C1C487352146C820B2B7D8"
    "A341655250FDB3E1E886EE9854390E68D62F5DC1EE18667D9E16400F596655EB14448858"
    "EB6660DB413B30DE90A8D66A36CE1ABAC7E3A618A834FF3A8A5062F1F432925D1885262D"
    "1C4F358CDC56A2F2C0EDA8C5D01B5E99F8208EA5BE7A74955C3DDDA676A7DDCB4E06647C"
    "26B27E589DB229B10849BC833CD60B2499396658D5DAE08B470700CE2531210EC049BF18"
    "3E9C35FDF5E86EC39DB9DB04029D28148CDB5D7133BE5C3BDF33125317BADA8E480D8301"
    "43F606361FCAA893D6F9D9AC2951335F0C1024D7D7B966324F95A3BF046CE17EF180E4E8"
    "1E369D39C89E82FC3E6E921777D9752C603ABF2C2F767D1F766B4282B9A39F5FC44520B8"
    "097C8FE5A56C48C34AF5D8CB2A44BE890D8A4A57EABD61517EE9CFB7D9137163D144B23A"
    "CA0701E9121A6323CDC98C6242C992F3BC656E25E51D067FAB4C3AFC55F177528B0CE6D6"
    "77AB2329E7986DDD9B0B417ECA9721007C24796D05A34B908002621E0F5CF39D8C12E52C"
    "E95CBFAA21588ACB8E9725C77449FF2AF7C3C38409E115EE2C1C1F7AC6A6B29217173943"
    "6CAC38FC14CF4DBA04BDBCD270F2D4ECEB56BEEF8F87195729FE36DB62455476A97A04ED"
    "F1BE5CCAC4E";

std::string abyssinian__cerf__1 =
    "B1EAA35CEED9D6795A8505D6F420A33A6F7F5D7828062B1BF079FD61DCF98C3DBCD8FE7BC8"
    "CC60CC7BB92DC832A10E37A55E8E8BEA2917E7DAB44ECE3C657951E307EBF268C8346B35AC"
    "F73C4BEEC8E8EB41E75AE1D4A835EBEC7BE535F39F4AF7ACA2F18471D2676A5293B398D9D6"
    "46C6AD6E291EA43A6ECD5A0996432AB4E119FA3672D579B1DBEDBADE169A4511579D91CB03"
    "20295DAB91B89A3135B765EBD92A6BD711904D7C5422FFB4ED094B481C0A3EEC58B2801F23"
    "EAA7E36EAD33F62B260716A6F753A11C726000D9AEE10EF6270F2CD3712A709CDCBFDC94AB"
    "D65DEAD556BE5DBC41517B656E482FE1F68E028E8E75FC90E87FFDA0E2C102152B55ED5B31"
    "A07470373018706A4828848466B228A98CCDF01EFBE1ABF88DC1C500E1ED63AC80E7412F47"
    "3F3768B40D12FB4ED28D5E4E73E91A8FF4D88795564C31442C5A1D393F7CE99A5334AA0FDD"
    "0EEED16C262CFE435D5983A2239B3BBBEBD0977443A460DDAF728D3E145F8E934BD4969469"
    "93562BACA95B3F722CFCA4E5C1BC1BA2F0CCC4B4148A624F3C6AEA4C71BC9549A227EBBCD5"
    "44DDB04AB7A28D492BE7645650F6806B178D049BEFEA493ACE9A06CDA283ED3E2B3A402822"
    "6603D38E312D38DC08518C227283CD92AC53021AFE16C5A838C497C48FEF5AC3D9271A9A12"
    "09910116517FF5FF39DABBD0C0C22F64294BE1975F2FA966235E3";

T_PRNG(CHAOS_PRNG_ABYSSINIAN, abyssinian__cerf__0, abyssinian__cerf__1)

/// xoroshiro //////////////////////////////////////////////////////////////////

std::string xoroshiro128plus__cerf__0 =
    "BFA45D9590870BB8AF984A6E9FA1931FBF9EF2FE1DFD32D4921478D418E4DD928CB5873F38"
    "8F86014F4DCE65D1FD664DAB0140D71DBA615D22AAB89AECFF7138A9DCE186DEA86C6FB3E0"
    "5696A20CBDC111207689903511EFC6D36563833CBF2488A41D7D32890617CFFBD466232EC4"
    "4C7EB933BD0966B2290BE53F3C4C995C62C0490C17A903D1F9C12BEEF272861759196A9B8D"
    "784F499C69DF96E58F053E271F1975ABB20DDB7A31CEF1854258725AABF96DC45656C4CB15"
    "C2DC78281F6AA44A05EA340B02581E86ECB190D5A01950EDAA683294EA608885C6618A6418"
    "DDB8AA72239B886DBE41DA08D7D16E744805D13558C12B5D8D989A32B950836D9C0192F2A9"
    "A82F2C31A4A5156691E0D94B3975014997D4EA43E884BE90FA0F04B595ABD23A14779235DF"
    "D89B30A0FA823B7FBD83226AD78F7EB7703A277B22EE6F19C1FFD0D1CD5DF0BE8B446D23F3"
    "60D7EE8AFD641BB88AA9C531AC1069F7CE9AA09F9F6955B1FA4F6B73E7F9B821A2EECCE3B0"
    "86ED8FFFF3598221F0B3DCD56411DEF74CAEF4873513F3DABAD17259664B1AFF582ED4C736"
    "A8EA87ADDBC3FAAD1CB1420B9CA906D8F3379C5223D48A03455AC2E55266246D5DCC26A3F5"
    "045547994AF7AC3D4FA8ECC229A7243AD8EC9A9912C3637870BA943FD5C711A1C2FDD01B35"
    "10A6E9937EEE31446848CFDA6AB031E75E7BBB39AD18A50662368";

std::string xoroshiro128plus__cerf__1 =
    "5C473040FFEC3296944A45FE836F91BAA931695AFE6228F7AF08062D66CF571F969F4B355B"
    "7D77BCD62798C880753CFB6C84DDACFD5549652A35AC5CC3E9056769FFC7862F9944F7A4E5"
    "3DB1C992171B8894A9718549EC39FF65E3488E1E9C5938E82A993A431EB5D3DE2DC9D62657"
    "E6A444597CEB7796AF236679E0CA05FCCEB832B272AC3329FBC44BCE4E109F1A81DFCACC25"
    "A9D783A21857D95E9FCF0CA563585D9BBD3B2C4C2648202AD63C3E88CF55D26C4C0810A006"
    "8F26ECCA20A8AB8EF36FD39678E9C4A85A7BC19EBB46620F361B7756C82AE8A4ED79A4A2D1"
    "83B33AF9BE7EB61D479E7F82183D977FA7636FD1A6FBDAF694369C978ABF3DC935B59527A1"
    "79BD74C7897FB5065918C96FB1351FD5DF2E86EAE4514A4A3CDE64C754D5741B6C761C50BE"
    "22CDDB2D7A467F5B515456E0CDABB8F35DD493A1138BFEB1F477EE6F1B31C4D48CD546216E"
    "AC0D1A0AFB7969DD997FF6CD7B59428A77DA050591EC20DB3DD33B1B53407AA842720EED3B"
    "115F7C5E84F4399BCCF2322BF8463292E3062515B32426F06BE56E3D55DFF1FA88FCBD717B"
    "05B39407F878DF214DD59DBC405692150FE7CDF6B658AD19BE7BFC2D4E19CD9311F274CA58"
    "D5C0717EE5DA725E60E748E413F3A3C9F1447C6A8C1FB1138DC6091B8EAAC769E39599025B"
    "DB9E2ED60A56B5BEBF06C3547D5534045CE4D58BEC3A29F9D6226";

T_PRNG(CHAOS_PRNG_XOROSHIRO128PLUS, xoroshiro128plus__cerf__0,
       xoroshiro128plus__cerf__1)

std::string xoroshiro1024star__cerf__0 =
    "5D0F62D66DF1D4652B98E19FF0DF5BB7B1C8E64CF198D04137D2BA03C2EC1CD6D7DDDA780C"
    "622DACD6427FF93449EE370B2EC6D82A818320A40A529182F258715E6E4732C45B43A77AC1"
    "A729BD53226AD4A7E86273EDA4BCBE5DCE58E1EAF9DBC629BBC2E12D6ED1EEF251574B9108"
    "8CFF1620EEB1967C47D1B639E1B25D58E63E8D95B2BC3919C2FC7DC7A16847A24758A3A3D2"
    "97EB4B4B409981FE20D60E670EFFA1FA75E3D6497A6296FA76C1EE775E8DA443177DCFB2F4"
    "6C2AC0073CD628DC34EA31C84095C2606E355CBF2131004651E9A18342B38CE1A896920872"
    "E863CF6C71E2D4A22E6BDE28C69586297B1BA92C9F0234A952B133124ED92523741D2DAEF2"
    "CA47DB449FEB83553FB4D3A8729E28063A610889635C0937A2CA09A517BBA47CE682B936E4"
    "32936ACDCEC521BA477B96AFB9062609BE9F336C0E674B6203C4D7FBC175D4B55873BE1BC7"
    "37C6676AA20EA3A9994609491F809D17974465B2B2195078894527038C936D4FDC5AF60D8F"
    "A26ADCEF24EB16008C875D4EAA93D0147D08C83E17427305C185A103AAD67EC27F0CB529A8"
    "07EF5F8A22D438B8B6DD618525F1D6151514CACE9B8CE21A77E937163044E9729F411124EB"
    "F42AE528D2AC81CAB4E0F1ABA77F7E4D50F4371B2D236D81ECDCA5810C99528C339AFC8689"
    "8C6F6D1CF4DF8424C2E60C353D52CB61A11304B54FFD7AC964539";

std::string xoroshiro1024star__cerf__1 =
    "873D817A82E6DE268380EFD386348DFCA6B1B718FD87598764467594DAA9DDE629709C76A6"
    "BED5DE2292F8F3E2F754F5FD8CFEEA78C5A108BA10A7065C3519C04982ACD897A44706839F"
    "886B43A00B1A96F1D7E7911D0321559D98DAC9FE9FB17D2C9B0C83A8AF5B84AC60EDF42D3B"
    "C0CDDA4E5F41DC99A9449933056A9CE54CCF244B04316B35F7E187BD8B6A0C51D4AA07BDEF"
    "82C2BF14393BF8C503C88411E2D0A63E41598B376143B25B1216361D0C16D3EFA56FCC91C0"
    "E213693CE8A2BDAF8D3D8F5602E350069683AE2E9B9F1A23663A863B8F3197AB95CECA16C0"
    "111577657CB196EBEE91FF123E42F9145277A7D5053B9BD1F6F809FE5FB7345044E9600413"
    "255AFDBAB8310BFA5702666EC9DB76130E378CAB17BF75DBCF345B356C670463C877987304"
    "D57B684E6BB28DCE64BA02CF2A07EE57DB627BC6C5C2EB30D71F4629BD5111589BDF35CFAE"
    "CA96D55B89F25548011D3AC073CC4F1415CF78E76F6244E052BF89C4D5A87CCE02B278A648"
    "7CCD270B005BF3DED892B26A806C021300F7AA681D1EF7F19A23715536F29312003A486CE2"
    "EBB4835EE4EDC2B7886A4A5D42774EA4988F7B152A755A98ADBF3AFC76D253E20D3DC776DE"
    "11E4F8337D9CC4CB24608B9FFCE19B878D03CF3ACEFDBA1C277E9F71D05CD13BEB42C63FC2"
    "E1EB09AD642DD0A3F25409CF4B699D9223F0B8120991D68CF31F1F";

T_PRNG(CHAOS_PRNG_XOROSHIRO1024STAR, xoroshiro1024star__cerf__0,
       xoroshiro1024star__cerf__1)

/// kiss ///////////////////////////////////////////////////////////////////////

std::string kiss__cerf__0 =
    "40A67FCFADC6E535B69B51CC5EC177EA25E747ED1EA678CB6B430278EC9544241A5D3BDF50"
    "2BC9267B40A80C30259B43C12D5EEB57A3428F1EC758CE518CE85AF75394891FA2AEA892EE"
    "7A989BE542479BFEC6ACE498B3A8EF95121E1025B1BBA04C7DC19959270CCC0E497DD92E17"
    "F67ADFA31CFC8FF8A61B570698563333884B0457336C13AF387853EE2D60CCD944F254B38D"
    "428367C123A48D6A70B8FDEC063B1F7251BB42F0583225320D49E3594134364CC51BD6597A"
    "443498A49CAB5DEC8577CB786A6F4B4ADCCC446E01EA663E8FB4E8898CD7E947078C2C0154"
    "7CE0786A028C04C57C072F6C018B2A7E0B57EDBAB585AF76844AA2EBF548ED6A47B3094DE6"
    "043C85B8604D7EDD534C7FF6656EEE9AF181A21732841F277602A4DD1F5EDA5C1638A20E2E"
    "DF99A8589CB6EFB27B1A3A2348D49D9E7B96AD429EBEDF91C66F98DBA596260831238B8CEB"
    "F4CF030280786CF0A447F0F4EDB75AD6F5C21744E7126A4C4962B70EB068E3D9EA64BB247B"
    "26550324D8FD1EEB57763331245FC969A0FDA853F36624892C89747AA909381BCE2E046657"
    "3187C54AB8FAEEAC4A7F73D2E120D61799A36FEDC87ADE8BD50EFDD1F29C8D0E81EA78CA0F"
    "97875DFA83AA0F45B3D5603527551B4E2B60841867B02811B8614BB0939D366779AAB2A03C"
    "F6827D6519D955A8BE270408B7B6F7781EE8F5A6E3B95BF43835B32";

std::string kiss__cerf__1 =
    "BC849243902B51CFF6B404F92CA09AC7CD042EEABFEC94495A748709A76AE39F00A13E9391"
    "2CB2007ED7A021CFFA555471D2DC9F32AAEED54415F337A4F83822DA701F192ADEA1EAE96D"
    "C39693368B52DD0CD22F691FA0709479AD05B91455134849707366C7ACE653052766A888F8"
    "1F5CB9D02A9FD4D48524E1AD564CB0D2BECDBB9B472A6621107E2D69310CF243C212397580"
    "404E3154393B70C976091A5CB4597FBE2877D0ECD200FACC496610AFFE9836BEFD429A5B92"
    "A27A360B6CFC1D5FA930E888A2BCBD501A8F448C92633E19764BFC1773EB95D9AE2B2DFC7E"
    "11EE97FD76655E375B52ACBC95FE1D38ED007BF3B11271A67EFD397AE9548A07144DB2E3BD"
    "8B9E19C3039E43D0A7D7F7FD3ED595F63E04DEDBF4342E4E036375F2AAFBE33A8072CD4C1E"
    "B19464D2632A7783B7E3B11A1496033CF91DF909D4DCEE3DEB9E4A6226BA7524E8CEB6521C"
    "7A1DAB5E718ECD4628EFCE54186C3B1BB1BA38D027B4A8A9AD024E10435E19A787869B83B5"
    "5B8054240526DE2649D056471DA9332BE0057CCD42DEA22095C047EAE8ED49253C912D8284"
    "FC12B7A2356DC26CB7972DE14634FE631E4BEBC04FA979AF5E489455BFE32F68204EB19CF6"
    "A5173F7DECE28CF493B1DD5222F668030A502DA88E282048969E766940AED46B8FCEACD4B1"
    "33B9A9289123FA830CC8480C8C8A8AC5CBC311101CBF615691B4E";

T_PRNG(CHAOS_PRNG_KISS, kiss__cerf__0, kiss__cerf__1)