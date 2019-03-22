Chrome Extension
================

### 기본 구성
1. manifest.json
메타 데이터를 담은 JSON 형식의 파일
~~~
{
    "name": "chrome-basic-extension",
    "version": "0.0.1",
    "manifest_version": 2,
    "description": "크롬 기초 확장 프로그램",
    //"homepage_url": "https://hiseon.me",
    "background": {
        "scripts": [
            "background.js"
        ],
        "persistent": true
    },
    "browser_action": {
        "default_title": "Extension~"
    },
    "permissions": [
        "https://*/*",
        "http://*/*",
        "tabs"
    ]
}
~~~
2. browser_action


3. background



### 앞으로의 계획
0. 기초적인 개발 방법과 구성 등 소개
1. 간단한 주제로 구현
2. 아이디어를 결정해서 팀으로 또는 각자 프로젝트 진행
이후. 서로 문제점이나 기술같은거 공유하면서 내용 발표
