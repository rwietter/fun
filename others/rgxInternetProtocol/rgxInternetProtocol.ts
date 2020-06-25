let rgx = /^\d{0,3}.\d{0,3}.(\d{0,3}.\d{0,3}$)/;

let ip = "122.321.124.111";

let groupIp = ip.match(rgx)![1];

function matchInternetProtocol(lastGroupIp: string, searchIp: string) {
  if (lastGroupIp === searchIp) {
    console.log(`${true}: ${lastGroupIp} === ${searchIp}`);
  } else {
    console.log(`${false}: ${lastGroupIp} !== ${searchIp}`);
  }
}

matchInternetProtocol(groupIp, '124.111')
matchInternetProtocol(groupIp, "124.1131");
matchInternetProtocol(groupIp, "14.111");

// output

true: 124.111 === 124.111
false: 124.111 !== 124.1131
false: 124.111 !== 14.111  
