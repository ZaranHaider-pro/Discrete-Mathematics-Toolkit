#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "CourseModule.h"
#include "StudentGroupModule.h"
#include "InductionModule.h"
#include "LogicModule.h"
#include "SetModule.h"
#include "RelationsModule.h"
#include "FunctionsModule.h"
#include "ProofModule.h"
#include "ConsistencyModule.h"

void showCourseModuleMenu(CourseModule& cm);
void showStudentModuleMenu(StudentGroupModule& sg);
void showInductionModuleMenu(InductionModule& im);
void showLogicModuleMenu(LogicModule& lm);
void showSetModuleMenu(SetModule& sm);
void showRelationsModuleMenu(RelationsModule& rm);
void showFunctionsModuleMenu(FunctionsModule& f, FunctionsModule& g);
void showProofModuleMenu(ProofModule& pm);
void showConsistencyModuleMenu(ConsistencyModule& cmc);

int main() {
    CourseModule cm;
    StudentGroupModule sg;
    InductionModule im;
    LogicModule lm;
    SetModule sm;
    RelationsModule rm;
    FunctionsModule f("f");
    FunctionsModule g("g");
    ProofModule pm;
    ConsistencyModule cmc;

    while (true) {
        cout << "\n1. Course Scheduling Module\n";
        cout << "2. Student Group Module\n";
        cout << "3. Induction (Prerequisite) Module\n";
        cout << "4. Logic & Inference Engine\n";
        cout << "5. Set Operations Module\n";
        cout << "6. Relations Module\n";
        cout << "7. Functions Module\n";
        cout << "8. Proof & Verification Module\n";
        cout << "9. Consistency Checker Module\n";
        cout << "0. Exit\n";
        cout << "Enter option: ";

        int opt;
        cin >> opt;

        if (opt == 0) break;
        switch (opt) {
        case 1: showCourseModuleMenu(cm); break;
        case 2: showStudentModuleMenu(sg); break;
        case 3: showInductionModuleMenu(im); break;
        case 4: showLogicModuleMenu(lm); break;
        case 5: showSetModuleMenu(sm); break;
        case 6: showRelationsModuleMenu(rm); break;
        case 7: showFunctionsModuleMenu(f, g); break;
        case 8: showProofModuleMenu(pm); break;
        case 9: showConsistencyModuleMenu(cmc); break;
        default: cout << "Invalid option.\n"; break;
        }
    }
    return 0;
}

void showCourseModuleMenu(CourseModule& cm) {
    while (true) {
        cout << "\n--- Course Scheduling Module ---\n";
        cout << "1. Add Course\n2. Add Prerequisite\n3. Show Valid Order\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        if (c == 1) { string code, name; cin >> code >> name; cm.addCourse(code, name); }
        else if (c == 2) { string cr, pr; cin >> cr >> pr; cm.addPrerequisite(cr, pr); }
        else if (c == 3) cm.printOneValidOrder();
    }
}

void showStudentModuleMenu(StudentGroupModule& sg) {
    while (true) {
        cout << "\n--- Student Group Module ---\n";
        cout << "1. Add Student\n2. Show Students\n3. Form Groups\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        if (c == 1) { string n; cin >> n; sg.addStudent(n); }
        else if (c == 2) sg.printAllStudents();
        else if (c == 3) { int s; cin >> s; sg.formGroups(s); }
    }
}

void showInductionModuleMenu(InductionModule& im) {
    while (true) {
        cout << "\n--- Induction Module ---\n";
        cout << "1. Add Course\n2. Add Prerequisite\n3. Mark Completed\n4. List Courses\n5. List Completed\n6. Can Take?\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        string a, b;
        if (c == 1) cin >> a >> b, im.addCourse(a, b);
        else if (c == 2) cin >> a >> b, im.addPrerequisite(a, b);
        else if (c == 3) cin >> a, im.markCompletedForStudent(a);
        else if (c == 4) im.listCourses();
        else if (c == 5) im.listCompletedCourses();
        else if (c == 6) cin >> a, im.canStudentTakeCourse(a);
    }
}

void showLogicModuleMenu(LogicModule& lm) {
    while (true) {
        cout << "\n--- Logic Module ---\n";
        cout << "1. Add Fact\n2. Add Rule\n3. List Facts\n4. List Rules\n5. Infer\n6. Check Conflicts\n7. Clear\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        string p, s, v, p2, s2, v2;
        if (c == 1) cin >> p >> s >> v, lm.addFact(p, s, v);
        else if (c == 2) cin >> p >> s >> v >> p2 >> s2 >> v2, lm.addRule(p, s, v, p2, s2, v2);
        else if (c == 3) lm.listFacts();
        else if (c == 4) lm.listRules();
        else if (c == 5) lm.runInference();
        else if (c == 6) lm.checkConflicts();
        else if (c == 7) lm.clearFacts(), lm.clearRules();
    }
}

void showSetModuleMenu(SetModule& sm) {
    while (true) {
        cout << "\n--- Set Module ---\n";
        cout << "1. Create Set\n2. Add Element\n3. Show Sets\n4. Union\n5. Intersection\n6. Diff\n7. Subset\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        string A, B, x;
        if (c == 1) cin >> A, sm.createSet(A);
        else if (c == 2) cin >> A >> x, sm.addElementToSet(A, x);
        else if (c == 3) sm.displayAllSets();
        else if (c == 4) cin >> A >> B, sm.setUnion(A, B);
        else if (c == 5) cin >> A >> B, sm.setIntersection(A, B);
        else if (c == 6) cin >> A >> B, sm.setDifference(A, B);
        else if (c == 7) cin >> A >> B, sm.checkSubset(A, B);
    }
}

void showRelationsModuleMenu(RelationsModule& rm) {
    while (true) {
        cout << "\n--- Relations Module ---\n";
        cout << "1. Add Element\n2. Add Pair\n3. Show Set\n4. Show Relation\n5. Reflexive\n6. Symmetric\n7. Transitive\n8. Equivalence\n9. Partial Order\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        string a, b;
        if (c == 1) cin >> a, rm.addElement(a);
        else if (c == 2) cin >> a >> b, rm.addRelation(a, b);
        else if (c == 3) rm.printSet();
        else if (c == 4) rm.printRelation();
        else if (c == 5) cout << (rm.isReflexive() ? "Yes" : "No") << endl;
        else if (c == 6) cout << (rm.isSymmetric() ? "Yes" : "No") << endl;
        else if (c == 7) cout << (rm.isTransitive() ? "Yes" : "No") << endl;
        else if (c == 8) cout << (rm.isEquivalence() ? "Yes" : "No") << endl;
        else if (c == 9) cout << (rm.isPartialOrder() ? "Yes" : "No") << endl;
    }
}

void showFunctionsModuleMenu(FunctionsModule& f, FunctionsModule& g) {
    while (true) {
        cout << "\n--- Functions Module ---\n";
        cout << "1. Set Name\n2. Add Domain\n3. Add Codomain\n4. Map\n5. Show\n6. Check\n7. Inverse\n8. Compose\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        string a, b;
        if (c == 1) cin >> a, f.setName(a);
        else if (c == 2) cin >> a, f.addDomainElement(a);
        else if (c == 3) cin >> a, f.addCodomainElement(a);
        else if (c == 4) cin >> a >> b, f.addMapping(a, b);
        else if (c == 5) f.printDomain(), f.printCodomain(), f.printMapping();
        else if (c == 6) cout << (f.isInjective() ? "Injective\n" : "Not Injective\n")
            << (f.isSurjective() ? "Surjective\n" : "Not Surjective\n")
            << (f.isBijective() ? "Bijective\n" : "Not Bijective\n");
        else if (c == 7) f.printInverse();
        else if (c == 8) { showFunctionsModuleMenu(g, f); g.composeWith(f); }
    }
}

void showProofModuleMenu(ProofModule& pm) {
    while (true) {
        cout << "\n--- Proof Module ---\n";
        cout << "1. Induction\n2. Subset\n3. Reflexive\n4. Symmetric\n5. Transitive\n6. Injective\n7. Surjective\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        int k;
        if (c == 1) {
            cin >> k; vector<string> m(k); for (int i = 0;i < k;i++) cin >> m[i]; pm.printInductionProof(m);
        }
        else if (c == 2) {
            cin >> k; vector<string> m(k); for (int i = 0;i < k;i++) cin >> m[i]; pm.printSubsetProof(m);
        }
        else if (c == 3) {
            cin >> k; vector<string> m(k); for (int i = 0;i < k;i++) cin >> m[i]; pm.reflexiveProof(m);
        }
        else if (c == 4) {
            cin >> k; vector<pair<string, string>> p(k); for (int i = 0;i < k;i++) cin >> p[i].first >> p[i].second; pm.symmetricProof(p);
        }
        else if (c == 5) {
            cin >> k; vector<pair<string, string>> p(k), q(k);
            for (int i = 0;i < k;i++) cin >> p[i].first >> p[i].second >> q[i].first >> q[i].second;
            pm.transitiveProof(p, q);
        }
        else if (c == 6) {
            string x, y, z; cin >> x >> y >> z; pm.injectiveProof(x, y, z);
        }
        else if (c == 7) {
            cin >> k; vector<string> m(k); for (int i = 0;i < k;i++) cin >> m[i]; pm.surjectiveProof(m);
        }
    }
}

void showConsistencyModuleMenu(ConsistencyModule& cmc) {
    while (true) {
        cout << "\n--- Consistency Checker ---\n";
        cout << "1. Check\n0. Back\nEnter: ";
        int c; cin >> c;
        if (c == 0) break;
        cout << "Use standalone module for full validation.\n";
    }
}