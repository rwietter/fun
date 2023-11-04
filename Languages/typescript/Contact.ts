export interface Contact {
  phone: Phone;
  email: Email;
  socialMedia: SocialMedia<SocialNetwork>[];
  location: Location
}

type Location = {
  latitude: string;
  longitude: string;
}

type Phone = {
  countryCode: string;
  areaCode: string;
  number: string;
};

type SocialNetwork = 'facebook' | 'twitter' | 'instagram' | 'linkedin' | 'website'

type SocialMediaUrl<T extends SocialNetwork> = T extends 'website'
  ? `https://${string}`
  : `https://${T}.com/${string}`;

type SocialMedia<T extends SocialNetwork> = {
  network: T;
  url: SocialMediaUrl<SocialNetwork>
} & T;

type Email = {
  emailAddress: string;
  entryEmail: string;
  exitEmail: string;
}

const contactInfo: Contact = {
  email: {
    emailAddress:'',
    entryEmail: '',
    exitEmail: ''
  },
  location: {
    latitude: '',
    longitude: ''
  },
  phone: {
    countryCode: '',
    areaCode: '',
    number: ''
  },
  socialMedia: [{network: 'facebook', url: ''}]
}