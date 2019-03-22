Chrome Extension
================

### 기본 구성

1. manifest.json
메타 데이터를 담은 JSON 형식의 파일입니다.
~~~json
{
    "name": "Test",								
    "version": "0.0.1",							
    "manifest_version": 2,						//manifest 버전
    "description": "Chrome Extension Test",		
    "homepage_url": "https://kweb.korea.ac.kr",	
    "background": {								//백엔드 역할
        "scripts": [
            "background.js"
        ],
        "persistent": false
    },
    "browser_action": {							//아이콘 클릭 시
        "default_title": "Extension~",
        "default_page": "popup.html"
    },
    "permissions": [							//권한
        "tabs"
    ]
}
~~~
2. browser_action
- 아이콘과 클릭했을 때에 관련된 부분입니다.

3. background
- 말그대로 백그라운드에서 실행되는 부분입니다.


### 앞으로의 계획
0. 기초적인 개발 방법과 구성 등 소개
1. 간단한 주제로 구현
2. 아이디어를 결정해서 팀으로 또는 각자 프로젝트 진행
- 이후. 서로 문제점이나 기술같은거 공유하면서 내용 발표
