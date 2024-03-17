{"payload":{"allShortcutsEnabled":false,"fileTree":{"PicoCTF_2019/BinaryExploitation/HeapOverflow-450":{"items":[{"name":"description.md","path":"PicoCTF_2019/BinaryExploitation/HeapOverflow-450/description.md","contentType":"file"},{"name":"vuln","path":"PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln","contentType":"file"},{"name":"vuln.c","path":"PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c","contentType":"file"}],"totalCount":3},"PicoCTF_2019/BinaryExploitation":{"items":[{"name":"AfterLife-400","path":"PicoCTF_2019/BinaryExploitation/AfterLife-400","contentType":"directory"},{"name":"CanaRy-300","path":"PicoCTF_2019/BinaryExploitation/CanaRy-300","contentType":"directory"},{"name":"Ghost_Diary-500","path":"PicoCTF_2019/BinaryExploitation/Ghost_Diary-500","contentType":"directory"},{"name":"GoT-350","path":"PicoCTF_2019/BinaryExploitation/GoT-350","contentType":"directory"},{"name":"HeapOverflow-450","path":"PicoCTF_2019/BinaryExploitation/HeapOverflow-450","contentType":"directory"},{"name":"L1im1L355-400","path":"PicoCTF_2019/BinaryExploitation/L1im1L355-400","contentType":"directory"},{"name":"NewOverFlow-1-200","path":"PicoCTF_2019/BinaryExploitation/NewOverFlow-1-200","contentType":"directory"},{"name":"NewOverFlow2-250","path":"PicoCTF_2019/BinaryExploitation/NewOverFlow2-250","contentType":"directory"},{"name":"OverFlow0-100","path":"PicoCTF_2019/BinaryExploitation/OverFlow0-100","contentType":"directory"},{"name":"OverFlow1-150","path":"PicoCTF_2019/BinaryExploitation/OverFlow1-150","contentType":"directory"},{"name":"OverFlow2-250","path":"PicoCTF_2019/BinaryExploitation/OverFlow2-250","contentType":"directory"},{"name":"SecondLife-400","path":"PicoCTF_2019/BinaryExploitation/SecondLife-400","contentType":"directory"},{"name":"handy-shellcode-50","path":"PicoCTF_2019/BinaryExploitation/handy-shellcode-50","contentType":"directory"},{"name":"leap-frog-300","path":"PicoCTF_2019/BinaryExploitation/leap-frog-300","contentType":"directory"},{"name":"messy-malloc-300","path":"PicoCTF_2019/BinaryExploitation/messy-malloc-300","contentType":"directory"},{"name":"pointy-350","path":"PicoCTF_2019/BinaryExploitation/pointy-350","contentType":"directory"},{"name":"practice-run-1-50","path":"PicoCTF_2019/BinaryExploitation/practice-run-1-50","contentType":"directory"},{"name":"rop32","path":"PicoCTF_2019/BinaryExploitation/rop32","contentType":"directory"},{"name":"rop64","path":"PicoCTF_2019/BinaryExploitation/rop64","contentType":"directory"},{"name":"seed-sPRiNG-350","path":"PicoCTF_2019/BinaryExploitation/seed-sPRiNG-350","contentType":"directory"},{"name":"slippery-shellcode-200","path":"PicoCTF_2019/BinaryExploitation/slippery-shellcode-200","contentType":"directory"},{"name":"stringzz-300","path":"PicoCTF_2019/BinaryExploitation/stringzz-300","contentType":"directory"}],"totalCount":22},"PicoCTF_2019":{"items":[{"name":"BinaryExploitation","path":"PicoCTF_2019/BinaryExploitation","contentType":"directory"},{"name":"Cryptography","path":"PicoCTF_2019/Cryptography","contentType":"directory"},{"name":"Forensics","path":"PicoCTF_2019/Forensics","contentType":"directory"},{"name":"GeneralSkills","path":"PicoCTF_2019/GeneralSkills","contentType":"directory"},{"name":"ReverseEngineering","path":"PicoCTF_2019/ReverseEngineering","contentType":"directory"},{"name":"WebExploitation","path":"PicoCTF_2019/WebExploitation","contentType":"directory"}],"totalCount":6},"":{"items":[{"name":"2019csaw_red","path":"2019csaw_red","contentType":"directory"},{"name":"2019hitcon","path":"2019hitcon","contentType":"directory"},{"name":"2019ritsec","path":"2019ritsec","contentType":"directory"},{"name":"2019seccon","path":"2019seccon","contentType":"directory"},{"name":"2019tuctf","path":"2019tuctf","contentType":"directory"},{"name":"2020UTCTF","path":"2020UTCTF","contentType":"directory"},{"name":"2021OOO","path":"2021OOO","contentType":"directory"},{"name":"CTFdScraper","path":"CTFdScraper","contentType":"directory"},{"name":"HackLu-2019","path":"HackLu-2019","contentType":"directory"},{"name":"PicoCTF_2019","path":"PicoCTF_2019","contentType":"directory"},{"name":".gitmodules","path":".gitmodules","contentType":"file"},{"name":"README.md","path":"README.md","contentType":"file"},{"name":"common_patterns.txt","path":"common_patterns.txt","contentType":"file"}],"totalCount":13}},"fileTreeProcessingTime":5.703257,"foldersToFetch":[],"repo":{"id":211383424,"defaultBranch":"master","name":"b01lers-library","ownerLogin":"b01lers","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2019-09-27T18:55:24.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/21175796?v=4","public":true,"private":false,"isOrgOwned":true},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"600830f246508f687e18ef8e389189f41110a1bf","listCacheKey":"v0:1569610538.0","canEdit":false,"refType":"tree","currentOid":"600830f246508f687e18ef8e389189f41110a1bf"},"path":"PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c","currentUser":null,"blob":{"rawLines":["#include <stdlib.h>","#include <stdio.h>","#include <string.h>","","#define FLAGSIZE 128","","void win() {","  char buf[FLAGSIZE];","  FILE *f = fopen(\"flag.txt\",\"r\");","  fgets(buf,FLAGSIZE,f);","  fprintf(stdout,\"%s\\n\",buf);","  fflush(stdout);","}","","int main(int argc, char *argv[])","{","   char *fullname, *name, *lastname;","   fullname = malloc(666);","   name = malloc(66);","   lastname = malloc(66);","   printf(\"Oops! a new developer copy pasted and printed an address as a decimal...\\n\");","   printf(\"%d\\n\",fullname);","   printf(\"Input fullname\\n\");","   gets(fullname);","   printf(\"Input lastname\\n\");","   gets(lastname);","   free(fullname);","   puts(\"That is all...\\n\");","   free(name);","   free(lastname);","   exit(0);","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"}],[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":18,"cssClass":"pl-s"}],[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"}],[],[{"start":0,"end":7,"cssClass":"pl-k"},{"start":8,"end":16,"cssClass":"pl-c1"}],[],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":8,"cssClass":"pl-en"}],[{"start":2,"end":6,"cssClass":"pl-smi"},{"start":7,"end":10,"cssClass":"pl-s1"},{"start":11,"end":19,"cssClass":"pl-c1"}],[{"start":2,"end":6,"cssClass":"pl-smi"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":8,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":12,"end":17,"cssClass":"pl-en"},{"start":18,"end":28,"cssClass":"pl-s"},{"start":29,"end":32,"cssClass":"pl-s"}],[{"start":2,"end":7,"cssClass":"pl-en"},{"start":8,"end":11,"cssClass":"pl-s1"},{"start":12,"end":20,"cssClass":"pl-c1"},{"start":21,"end":22,"cssClass":"pl-s1"}],[{"start":2,"end":9,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s1"},{"start":17,"end":23,"cssClass":"pl-s"},{"start":24,"end":27,"cssClass":"pl-s1"}],[{"start":2,"end":8,"cssClass":"pl-en"},{"start":9,"end":15,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":8,"cssClass":"pl-en"},{"start":9,"end":12,"cssClass":"pl-smi"},{"start":13,"end":17,"cssClass":"pl-s1"},{"start":19,"end":23,"cssClass":"pl-smi"},{"start":24,"end":25,"cssClass":"pl-c1"},{"start":25,"end":29,"cssClass":"pl-s1"}],[],[{"start":3,"end":7,"cssClass":"pl-smi"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":9,"end":17,"cssClass":"pl-s1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-s1"},{"start":26,"end":27,"cssClass":"pl-c1"},{"start":27,"end":35,"cssClass":"pl-s1"}],[{"start":3,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":20,"cssClass":"pl-en"},{"start":21,"end":24,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":16,"cssClass":"pl-en"},{"start":17,"end":19,"cssClass":"pl-c1"}],[{"start":3,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":20,"cssClass":"pl-en"},{"start":21,"end":23,"cssClass":"pl-c1"}],[{"start":3,"end":9,"cssClass":"pl-en"},{"start":10,"end":86,"cssClass":"pl-s"}],[{"start":3,"end":9,"cssClass":"pl-en"},{"start":10,"end":16,"cssClass":"pl-s"},{"start":17,"end":25,"cssClass":"pl-s1"}],[{"start":3,"end":9,"cssClass":"pl-en"},{"start":10,"end":28,"cssClass":"pl-s"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":16,"cssClass":"pl-s1"}],[{"start":3,"end":9,"cssClass":"pl-en"},{"start":10,"end":28,"cssClass":"pl-s"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":16,"cssClass":"pl-s1"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":16,"cssClass":"pl-s1"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":26,"cssClass":"pl-s"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":12,"cssClass":"pl-s1"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":16,"cssClass":"pl-s1"}],[{"start":3,"end":7,"cssClass":"pl-en"},{"start":8,"end":9,"cssClass":"pl-c1"}],[]],"colorizedLines":null,"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/b01lers/b01lers-library/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null},"displayName":"vuln.c","displayUrl":"https://github.com/b01lers/b01lers-library/blob/600830f246508f687e18ef8e389189f41110a1bf/PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c?raw=true","headerInfo":{"blobSize":"687 Bytes","deleteTooltip":"You must be signed in to make or propose changes","editTooltip":"You must be signed in to make or propose changes","ghDesktopPath":null,"isGitLfs":false,"onBranch":false,"shortPath":"f74b958","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fb01lers%2Fb01lers-library%2Fblob%2F600830f246508f687e18ef8e389189f41110a1bf%2FPicoCTF_2019%2FBinaryExploitation%2FHeapOverflow-450%2Fvuln.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"32","truncatedSloc":"29"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/b01lers/b01lers-library/blob/600830f246508f687e18ef8e389189f41110a1bf/PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","releasePath":"/b01lers/b01lers-library/releases/new?marketplace=true","showPublishActionBanner":false},"rawBlobUrl":"https://github.com/b01lers/b01lers-library/raw/600830f246508f687e18ef8e389189f41110a1bf/PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c","renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"symbolsEnabled":true,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timed_out":false,"not_analyzed":false,"symbols":[{"name":"FLAGSIZE","kind":"macro","ident_start":68,"ident_end":76,"extent_start":60,"extent_end":82,"fully_qualified_name":"FLAGSIZE","ident_utf16":{"start":{"line_number":4,"utf16_col":8},"end":{"line_number":4,"utf16_col":16}},"extent_utf16":{"start":{"line_number":4,"utf16_col":0},"end":{"line_number":6,"utf16_col":0}}},{"name":"win","kind":"function","ident_start":87,"ident_end":90,"extent_start":87,"extent_end":92,"fully_qualified_name":"win","ident_utf16":{"start":{"line_number":6,"utf16_col":5},"end":{"line_number":6,"utf16_col":8}},"extent_utf16":{"start":{"line_number":6,"utf16_col":5},"end":{"line_number":6,"utf16_col":10}}},{"name":"main","kind":"function","ident_start":232,"ident_end":236,"extent_start":232,"extent_end":260,"fully_qualified_name":"main","ident_utf16":{"start":{"line_number":14,"utf16_col":4},"end":{"line_number":14,"utf16_col":8}},"extent_utf16":{"start":{"line_number":14,"utf16_col":4},"end":{"line_number":14,"utf16_col":32}}}]}},"copilotInfo":null,"copilotAccessAllowed":false,"csrf_tokens":{"/b01lers/b01lers-library/branches":{"post":"osyK3qjs0L62xTVnrOLB99OsyGO6caqq7agpwBjE4HvAuWPc7QKnO-Q946R4f866oJk-Odoob8SW6VfxeA5saA"},"/repos/preferences":{"post":"tdLACNyfLhMD6CrKI2rCYotoLUgx5_mBQQKRdBHFTqyR1KkHF4C3wFFnhDLKyKiGrP3wS6xuq2dr4ILq-6PdEA"}}},"title":"b01lers-library/PicoCTF_2019/BinaryExploitation/HeapOverflow-450/vuln.c at 600830f246508f687e18ef8e389189f41110a1bf · b01lers/b01lers-library"}